function generatePassword() {
    const length = parseInt(document.getElementById("length").value);
    const useUpper = document.getElementById("uppercase").checked;
    const useLower = document.getElementById("lowercase").checked;
    const useNumbers = document.getElementById("numbers").checked;
    const useSymbols = document.getElementById("symbols").checked;

    const upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const lower = "abcdefghijklmnopqrstuvwxyz";
    const numbers = "0123456789";
    const symbols = "!@#$%^&*()_+-=[]{}|;:',.<>/?";

    let validChars = "";
    if (useUpper) validChars += upper;
    if (useLower) validChars += lower;
    if (useNumbers) validChars += numbers;
    if (useSymbols) validChars += symbols;

    const passwordOutput = document.getElementById("passwordOutput");

    if (validChars.length === 0) {
        passwordOutput.textContent = "⚠ Please select at least one character type.";
        return;
    }

    let password = "";
    for (let i = 0; i < length; i++) {
        const randIndex = Math.floor(Math.random() * validChars.length);
        password += validChars[randIndex];
    }

    passwordOutput.textContent = password;
    evaluateStrength(password, useUpper, useLower, useNumbers, useSymbols);
}

function copyPassword() {
    const text = document.getElementById("passwordOutput").textContent;
    if (!text || text.includes("Please select")) return;

    navigator.clipboard.writeText(text).then(() => {
        alert("Password copied to clipboard!");
    });
}

function evaluateStrength(password, useUpper, useLower, useNumbers, useSymbols) {
    const strengthText = document.getElementById("strengthMeter");
    let score = 0;

    if (password.length >= 8) score++;
    if (password.length >= 12) score++;
    if (useUpper) score++;
    if (useLower) score++;
    if (useNumbers) score++;
    if (useSymbols) score++;

    // Basic strength logic
    if (score <= 3) {
        strengthText.textContent = "Strength: Weak";
        strengthText.className = "strength weak";
    } else if (score <= 5) {
        strengthText.textContent = "Strength: Medium";
        strengthText.className = "strength medium";
    } else {
        strengthText.textContent = "Strength: Strong";
        strengthText.className = "strength strong";
    }
}