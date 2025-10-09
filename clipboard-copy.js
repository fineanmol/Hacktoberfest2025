// clipboard-history.js
// --------------------
// Automatically records everything copied (Ctrl + C / right click)
// Stores in localStorage and logs in console

let clipboardHistory = JSON.parse(
  localStorage.getItem("clipboardHistory") || "[]"
);

function updateStorage() {
  localStorage.setItem("clipboardHistory", JSON.stringify(clipboardHistory));
}

function showClipboardHistory() {
  console.clear();
  console.log("📋 Clipboard History:");
  clipboardHistory.forEach((item, index) => {
    console.log(`${index + 1}: ${item}`);
  });
}

// Listen to copy events
document.addEventListener("copy", (event) => {
  const selection = document.getSelection().toString().trim();
  if (selection) {
    clipboardHistory.push(selection);
    updateStorage();
    console.log(`✅ Copied: "${selection}"`);
  }
});

// Expose a way to view or clear history manually
window.showClipboardHistory = showClipboardHistory;
window.clearClipboardHistory = () => {
  clipboardHistory = [];
  updateStorage();
  console.log("🧹 Clipboard history cleared.");
};
