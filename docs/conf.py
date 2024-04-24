import os
import pkgutil
import sys
from pathlib import Path

sys.path.insert(0, os.path.abspath("../"))


# Configuration file for the Sphinx documentation builder.
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = "STEN"
copyright = "2023, Structura Engineering"
author = "Structura Engineering"
release = "1.0"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.napoleon",
]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "sphinx_book_theme"
html_theme_options = {
    "logo": {
        "text": "STEN Wiki",
    },
    "repository_url": "https://github.com/Structura-Engineering/AutoFrameCAD",
    "repository_branch": "main",
    "use_download_button": True,
    "use_fullscreen_button": True,
    "use_issues_button": True,
    "use_repository_button": True,
}
html_title = "STEN Wiki"
html_logo = "https://raw.githubusercontent.com/Structura-Engineering/.github/main/icons/favicon.webp"
html_favicon = "https://raw.githubusercontent.com/Structura-Engineering/.github/main/icons/sten_short_logo.svg"
html_static_path = ["_static"]
html_css_files = ["custom.css"]

# -- Options for autodoc -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/extensions/autodoc.html


# -- Options for napoleon ----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/extensions/napoleon.html
napoleon_google_docstring = True
napoleon_numpy_docstring = False
napoleon_include_init_with_doc = False
napoleon_include_private_with_doc = False
napoleon_include_special_with_doc = False
napoleon_use_admonition_for_examples = False
napoleon_use_admonition_for_notes = False
napoleon_use_admonition_for_references = False
napoleon_use_ivar = False
napoleon_use_param = True
napoleon_use_rtype = True
napoleon_preprocess_types = False
napoleon_type_aliases = None
napoleon_attr_annotations = True

# -- Generate _modules files --------------------------------------------------


class RSTGenerator:
    """A class to generate rst files for the modules."""

    def __init__(self, module_names: list[str], output_dir: str) -> None:
        """Initialize the RSTGenerator.

        Args:
            module_names (list[str]): The names of the modules.
            output_dir (str): The output directory.
        """
        self.module_names = module_names
        self.output_dir = Path(output_dir)

    @staticmethod
    def generate_rst(module_name: str) -> str:
        """Generate the rst content for a module.

        Args:
            module_name (str): The name of the module.

        Returns:
            str: The rst content for the module.
        """
        rst_content = f"{module_name}\n"
        rst_content += "=" * len(module_name) + "\n\n"

        for _, name, _ in pkgutil.iter_modules(
            [os.path.join("..", module_name)]
        ):
            if name == "tests":
                continue
            rst_content += f".. automodule:: {module_name}.{name}\n"
            rst_content += "   :members:\n"
            rst_content += "   :undoc-members:\n"
            rst_content += "   :show-inheritance:\n\n"

        return rst_content

    def write_rst_files(self) -> None:
        """Write the rst files for the modules."""
        os.makedirs(self.output_dir, exist_ok=True)
        for module_name in self.module_names:
            rst_content = self.generate_rst(module_name)
            with open(
                os.path.join(self.output_dir, f"{module_name}.rst"), "wb"
            ) as f:
                f.write(rst_content.encode())


RSTGenerator(["AutoFrameCAD", "StenLib"], "_modules").write_rst_files()
