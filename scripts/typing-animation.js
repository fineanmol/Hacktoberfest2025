class TypingAnimation {
  constructor(element, text, options = {}) {
    this.element = element;
    this.text = text;
    this.speed = options.speed || 150;
    this.showCursor = options.showCursor !== false;
    this.cursorChar = options.cursorChar || "|";
    this.delay = options.delay || 1000;
    this.loop = options.loop || false;

    this.currentIndex = 0;
    this.isTyping = false;
    this.isDeleting = false;
  }

  async start() {
    await this.sleep(this.delay);
    this.element.innerHTML = "";
    this.type();
  }

  async type() {
    this.isTyping = true;
    for (let i = 0; i <= this.text.length; i++) {
      if (!this.isTyping) break;
      const currentText = this.text.substring(0, i);
      this.updateElement(currentText);
      await this.sleep(this.speed);
    }

    this.isTyping = false;

    if (this.showCursor) {
      this.addBlinkingCursor();
    }
    if (this.loop) {
      await this.sleep(2000);
      this.delete();
    }
  }

  async delete() {
    this.isDeleting = true;

    for (let i = this.text.length; i >= 0; i--) {
      if (!this.isDeleting) break;
      const currentText = this.text.substring(0, i);
      this.updateElement(currentText);
      await this.sleep(this.speed / 2);
    }

    this.isDeleting = false;
    await this.sleep(500);
    this.type();
  }

  updateElement(text) {
    if (this.showCursor && (this.isTyping || this.isDeleting)) {
      this.element.innerHTML =
        text + `<span class="typing-cursor">${this.cursorChar}</span>`;
    } else {
      this.element.innerHTML = text;
    }
  }

  addBlinkingCursor() {
    const currentText = this.element.innerHTML;
    this.element.innerHTML =
      currentText +
      `<span class="typing-cursor-blink">${this.cursorChar}</span>`;
  }

  sleep(ms) {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }

  stop() {
    this.isTyping = false;
    this.isDeleting = false;
  }
}

document.addEventListener("DOMContentLoaded", function () {
  const heading = document.querySelector(".heading b");
  if (heading) {
    const originalText = heading.textContent.trim();
    const typingAnimation = new TypingAnimation(heading, originalText, {
      speed: 120,
      delay: 500,
      showCursor: true,
      loop: false,
    });
    typingAnimation.start();
    const headingContainer = document.querySelector(".heading");
    if (headingContainer) {
      headingContainer.style.opacity = "0";
      headingContainer.style.transform = "translateY(20px)";
      headingContainer.style.transition = "all 0.6s ease";

      setTimeout(() => {
        headingContainer.style.opacity = "1";
        headingContainer.style.transform = "translateY(0)";
      }, 200);
    }
  }
});
