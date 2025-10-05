/**
 * tab-hide.js
 *
 * A simple script to dynamically change the tab title
 * and hide the favicon for privacy or demonstration purposes.
 * Can be run in the browser console on any page.
 */

(function hideTab() {
  try {
    // Prompt user for new tab title
    const newTitle = prompt(
      "Enter a new tab title (leave empty for none):",
      ""
    );
    if (newTitle !== null) {
      document.title = newTitle;
    }

    // Remove favicon safely
    const favicon = document.querySelector("link[rel~='icon']");
    if (favicon) {
      // Replace with a transparent 1x1 PNG instead of removing entirely
      favicon.href =
        "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAQAAAC1HAwCAAAAC0lEQVR4nGNgYAAAAAMAAWgmWQ0AAAAASUVORK5CYII=";
    }

    console.log("✅ Tab title updated and favicon hidden successfully.");
  } catch (err) {
    console.error("❌ Error hiding tab title or favicon:", err);
  }
})();
