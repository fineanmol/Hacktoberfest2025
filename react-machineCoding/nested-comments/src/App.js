import logo from "./logo.svg";
import "./App.css";
import { useState } from "react";
import { v4 as uuidv4 } from "uuid";

function App() {
  const [clickedPost, setClickedPost] = useState(null);
  const [clickedComment, setClickedComment] = useState(null);
  const posts = [
    {
      id: uuidv4(),
      postData: "Post 01",
      comments: [
        {
          id: uuidv4(),
          commentData: "Comment 01",
          comments: [
            {
              id: uuidv4(),
              commentData: "Reply 01",
              comments: [],
            },
          ],
        },
        {
          id: uuidv4(),
          commentData: "Comment 02",
          comments: [],
        },
      ],
    },
    {
      id: uuidv4(),
      postData: "Post 02",
      comments: [
        {
          id: uuidv4(),
          commentData: "Comment 01",
          comments: [],
        },
        {
          id: uuidv4(),
          commentData: "Comment 02",
          comments: [],
        },
      ],
    },
  ];

  const [data, setData] = useState(posts);
  const [addedText, setAddedText] = useState("");

  const clickPostComment = (post) => {
    setClickedPost(post);
  };

  const handleInputChange = (e) => {
    setAddedText(e.target.value);
  };

  const addPostComment = (post) => {
    setClickedPost(post);
    const newData = data.map((item) => {
      if (item.id === post.id) {
        return {
          ...item,
          comments: [
            ...item.comments,
            {
              id: uuidv4(),
              commentData: addedText,
              comments: [],
            },
          ],
        };
      }
      return item;
    });
    setData(newData);
    closePostComment();
  };

  const closePostComment = (post) => {
    setClickedPost(null);
  };

  const handleClickComment = (e, comment) => {
    setClickedComment(comment);
  };

  const addNestedReply = (parentComments, inputComment) => {
    //   // Base condition: If there are no comments, return an empty array

    if (parentComments.length === 0) {
      return [];
    }

    return parentComments.map((comment) => {
      //     // If the comment matches the input comment, add a new reply

      if (comment.id === inputComment.id) {
        return {
          ...comment,
          comments: [
            ...comment.comments,
            {
              id: uuidv4(),
              commentData: addedText,
              comments: [],
            },
          ],
        };
      }

      //     // Recursively check nested comments

      if (comment.comments.length > 0) {
        return {
          ...comment,
          comments: addNestedReply(comment.comments, inputComment),
        };
      }
      //     // If no match and no nested comments, return the comment as is

      return comment;
    });
  };

  const addCommentReply = (postId, comment) => {
    let newData = data.map((post) => {
      if (post.id === postId) {
        return {
          ...post,
          comments: addNestedReply(post.comments, comment),
        };
      }
      return post;
    });
    setClickedComment(null);
    setData(newData);
  };

  const closeCommentReply = (comment) => {
    setClickedComment(null);
  };

  const renderAllComments = (postId, comments) => {
    if (comments.length === 0) {
      return null;
    }

    return (
      <div>
        {comments.map((comment) => {
          return (
            <div
              key={comment.id}
              className="single-comment"
              style={{ marginLeft: "20px" }}
            >
              {comment.commentData}

              {clickedComment?.id !== comment.id ? (
                <button onClick={(e) => handleClickComment(e, comment)}>
                  Add Reply
                </button>
              ) : (
                <>
                  <input type="text" onChange={(e) => handleInputChange(e)} />
                  <button onClick={() => addCommentReply(postId, comment)}>
                    Add
                  </button>
                  <button onClick={() => closeCommentReply(comment)}>
                    Close
                  </button>
                </>
              )}

              {comment?.comments?.length > 0 &&
                renderAllComments(postId, comment.comments)}
            </div>
          );
        })}
      </div>
    );
  };
  return (
    <div className="App">
      {data.map((post) => {
        return (
          <div className="single-post">
            <div className="single-post-header">
              {post.postData}
              {clickedPost?.id !== post.id ? (
                <button onClick={() => clickPostComment(post)}>
                  Add Comment
                </button>
              ) : (
                <>
                  <input type="text" onChange={(e) => handleInputChange(e)} />
                  <button onClick={() => addPostComment(post)}>Add</button>
                  <button onClick={() => closePostComment(post)}>Close</button>
                </>
              )}
            </div>
            <div className="comment-box">
              {renderAllComments(post.id, post.comments)}
            </div>
          </div>
        );
      })}
    </div>
  );
}

export default App;
