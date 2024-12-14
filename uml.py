import os
import re

def extract_classes_from_file(file_path):
    """Extracts classes, attributes, and methods from a .h or .cpp file."""
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as file:
        content = file.read()

    classes = []
    # Regex to identify classes (basic support for single inheritance)
    class_regex = re.compile(r'class\s+(\w+)\s*(?::\s*public\s+(\w+))?\s*{')

    # A more general regex for attributes:
    # This tries to capture lines like:
    #   int x; or std::string name; or Foo<int>* ptr;
    # Group 1: The type (anything that looks like a type, including templates and pointers)
    # Group 2: The attribute name
    attribute_regex = re.compile(
        r'(?:public|protected|private)?\s*(?:virtual\s+)?([A-Za-z_]\w*(?:<[^>]+>)?(?:\s*[\*&]+)?(?:\s*[A-Za-z_]\w*(?:<[^>]+>)?\s*[\*&]+)?)\s+(\w+)\s*;\s*$'
        , re.MULTILINE
    )

    # A more general regex for methods:
    # Similar logic, but now we require parentheses and a trailing semicolon
    method_regex = re.compile(
        r'(?:public|protected|private)?\s*(?:virtual\s+)?([A-Za-z_]\w*(?:<[^>]+>)?(?:\s*[\*&]+)?(?:\s*[A-Za-z_]\w*(?:<[^>]+>)?\s*[\*&]+)?)\s+(\w+)\s*\(([^)]*)\)\s*;\s*$'
        , re.MULTILINE
    )

    for class_match in class_regex.finditer(content):
        class_name = class_match.group(1)
        parent_class = class_match.group(2)
        class_block = extract_class_block(content, class_match.start())
        # Find attributes and methods inside the class block
        attributes = [m.group(2) for m in attribute_regex.finditer(class_block)]
        methods = [m.group(2) for m in method_regex.finditer(class_block)]
        classes.append({
            'name': class_name,
            'parent': parent_class,
            'attributes': attributes,
            'methods': methods
        })

    return classes


def extract_class_block(content, class_start):
    """Extracts the block of code defining a class."""
    open_braces = 0
    for i, char in enumerate(content[class_start:], start=class_start):
        if char == '{':
            open_braces += 1
        elif char == '}':
            open_braces -= 1
        if open_braces == 0 and i > class_start:
            return content[class_start:i + 1]
    return ""


def generate_plantuml(classes, output_path='uml.puml'):
    """Generates a PlantUML file from the extracted class data."""
    with open(output_path, 'w') as file:
        file.write("@startuml\n\n")
        for cls in classes:
            file.write(f"class {cls['name']} {{\n")
            # Add attributes
            for attr in cls['attributes']:
                file.write(f"  - {attr}\n")
            # Add methods
            for method in cls['methods']:
                file.write(f"  + {method}()\n")
            file.write("}\n")
            # Add inheritance
            if cls['parent']:
                file.write(f"{cls['parent']} <|-- {cls['name']}\n")
        file.write("\n@enduml\n")


def main():
    # Directory containing the .h and .cpp files
    directory = '.'
    all_classes = []

    for root, _, files in os.walk(directory):
        for file_name in files:
            if file_name.endswith(('.h', '.cpp')):
                file_path = os.path.join(root, file_name)
                classes = extract_classes_from_file(file_path)
                all_classes.extend(classes)

    if all_classes:
        generate_plantuml(all_classes)
        print("UML diagram generated: uml.puml")
    else:
        print("No classes found.")


if __name__ == "__main__":
    main()
