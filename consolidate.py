import os

def consolidate_code(output_file='consolidated_code.txt', directory='.'):
    """Consolidates all .h and .cpp files in the directory into a single file."""
    with open(output_file, 'w', encoding='utf-8') as outfile:
        for root, _, files in os.walk(directory):
            for file_name in files:
                if file_name.endswith(('.h', '.cpp')):
                    file_path = os.path.join(root, file_name)
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        # Write a separator to indicate the source file
                        outfile.write(f"// --- Start of {file_name} ---\n")
                        outfile.write(infile.read())
                        outfile.write(f"\n// --- End of {file_name} ---\n\n")
    print(f"All files consolidated into {output_file}")

if __name__ == "__main__":
    consolidate_code()
