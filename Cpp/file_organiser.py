import os
import shutil
from collections import defaultdict

def organize_files_by_type(directory_path):
    """
    Organizes all files in the given directory into subfolders 
    based on their file extension (e.g., all .txt files go into a 'TEXT' folder).
    """
    # 1. Check if the directory exists
    if not os.path.isdir(directory_path):
        print(f"Error: Directory not found at '{directory_path}'")
        return

    print(f"Starting organization in: {directory_path}")

    # 2. Iterate over all items in the directory
    for filename in os.listdir(directory_path):
        file_path = os.path.join(directory_path, filename)

        # Skip if it's a directory itself, or the script file
        if os.path.isdir(file_path):
            continue
        
        # 3. Get the file extension and create a folder name
        # os.path.splitext returns a tuple: ('/path/to/file', '.ext')
        base_name, extension = os.path.splitext(filename)
        
        # Standardize the folder name (e.g., '.pdf' -> 'PDF', '' -> 'NO_EXTENSION')
        if extension:
            folder_name = extension[1:].upper() # Remove the dot and capitalize
        else:
            folder_name = "NO_EXTENSION"
        
        # 4. Define the path for the new folder and the new file location
        destination_folder = os.path.join(directory_path, folder_name)
        destination_path = os.path.join(destination_folder, filename)

        try:
            # 5. Create the destination folder if it doesn't exist
            if not os.path.exists(destination_folder):
                os.makedirs(destination_folder)
                print(f"Created folder: {folder_name}")

            # 6. Move the file
            shutil.move(file_path, destination_path)
            print(f"Moved: '{filename}' -> '{folder_name}/{filename}'")

        except Exception as e:
            print(f"Could not move file {filename}. Error: {e}")

    print("\nFile organization complete! ✅")

# --- USER CONFIGURATION SECTION ---
# IMPORTANT: Change this path to the folder you want to clean up!
folder_to_organize = "/path/to/your/desktop/downloads" 

# Execute the function
organize_files_by_type(folder_to_organize)