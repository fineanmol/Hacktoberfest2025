# summarizer.py
"""
Text Summarization Project
Author: Your Name
Description: Summarizes text into concise summaries using Hugging Face Transformers.
"""

from transformers import pipeline
from rich.console import Console
from rich.panel import Panel

console = Console()

def summarize_text(text, max_len=120, min_len=30):
    """Summarizes the given text using Hugging Face pipeline."""
    summarizer = pipeline("summarization")
    summary = summarizer(text, max_length=max_len, min_length=min_len, do_sample=False)
    return summary[0]['summary_text']

def main():
    console.print("[bold yellow]Welcome to Text Summarization![/bold yellow]\n")
    text = console.input("Enter the text to summarize:\n> ")

    console.print(Panel("[bold cyan]Original Text[/bold cyan]\n" + text, title="Input Text"))

    summary = summarize_text(text)
    console.print(Panel("[bold green]Summarized Text[/bold green]\n" + summary, title="Summary"))

if __name__ == "__main__":
    main()
