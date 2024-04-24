import os
import pkgutil


class Generator:
    """A class that generates data."""

    @staticmethod
    def _gen_sphinx_modules(module_names: list[str], output_dir: str) -> None:
        """Generate rst files for the Sphinx modules.

        Args:
            module_names (list[str]): The names of the modules.
            output_dir (str): The output directory.
        """
        os.makedirs(output_dir, exist_ok=True)
        for module_name in module_names:
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

            with open(
                os.path.join(output_dir, f"{module_name}.rst"), "wb"
            ) as f:
                f.write(rst_content.encode())

    sphinx_modules = _gen_sphinx_modules
