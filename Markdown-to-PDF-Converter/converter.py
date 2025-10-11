vfrom reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer
from reportlab.lib.styles import getSampleStyleSheet
import sys

def md_to_pdf(input_file, output_file):
    try:
        with open(input_file, "r", encoding="utf-8") as f:
            md_text = f.read()

        # Convert markdown-like syntax to simple paragraphs
        styles = getSampleStyleSheet()
        story = []

        for line in md_text.split("\n"):
            if line.startswith("# "):  # H1
                story.append(Paragraph(f"<b><font size=16>{line[2:]}</font></b>", styles['Title']))
            elif line.startswith("## "):  # H2
                story.append(Paragraph(f"<b><font size=14>{line[3:]}</font></b>", styles['Heading2']))
            elif line.startswith("### "):  # H3
                story.append(Paragraph(f"<b><font size=12>{line[4:]}</font></b>", styles['Heading3']))
            else:
                story.append(Paragraph(line, styles['Normal']))
            story.append(Spacer(1, 12))

        doc = SimpleDocTemplate(output_file)
        doc.build(story)
        print(f"PDF created successfully: {output_file}")

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python converter.py input.md output.pdf")
    else:
        md_to_pdf(sys.argv[1], sys.argv[2])
