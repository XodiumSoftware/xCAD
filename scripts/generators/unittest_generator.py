import os


def generate_unittest_file(dir_path, test_name, test_content):
    os.makedirs(dir_path, exist_ok=True)
    with open(os.path.join(dir_path, f"{test_name}_test.py"), "w") as file:
        file.write("import unittest\n\n")
        file.write(test_content)


def main():
    src_dir = "./src"
    for root, _, files in os.walk(src_dir):
        for file in files:
            if file.endswith(".py") and "__" not in file:
                test_name = os.path.splitext(file)[0]
                test_content = f"""
class Test{test_name.capitalize()}(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(1, 1)
"""
                test_dir = os.path.join("tests", os.path.relpath(root, src_dir))
                os.makedirs(test_dir, exist_ok=True)
                generate_unittest_file(test_dir, test_name, test_content)


if __name__ == "__main__":
    main()
