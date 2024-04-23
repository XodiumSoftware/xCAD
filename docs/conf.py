import os
import sys

sys.path.insert(0, os.path.abspath("../"))


# Configuration file for the Sphinx documentation builder.
#
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

templates_path = ["_templates"]
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
html_logo = "https://raw.githubusercontent.com/Structura-Engineering/.github/main/icons/favicon.ico"
html_favicon = "https://raw.githubusercontent.com/Structura-Engineering/.github/main/icons/sten_short_logo.svg"
html_static_path = ["_static"]
html_css_files = ["custom.css"]  # resizing the icon didnt work.

# -- Options for autodoc -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/extensions/autodoc.html


# -- Options for napoleon ----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/extensions/napoleon.html
napoleon_google_docstring = True
napoleon_numpy_docstring = False
napoleon_include_init_with_doc = True
napoleon_include_private_with_doc = True
napoleon_include_special_with_doc = True
napoleon_use_admonition_for_examples = False
napoleon_use_admonition_for_notes = False
napoleon_use_admonition_for_references = False
napoleon_use_ivar = False
napoleon_use_param = True
napoleon_use_rtype = True
napoleon_preprocess_types = False
napoleon_type_aliases = None
napoleon_attr_annotations = True
