from subprocess import run
from venv import create

create(
    env_dir=".venv",
    system_site_packages=False,
    clear=False,
    symlinks=False,
    with_pip=True,
    prompt=None,
    upgrade_deps=True,
)


run(
    [".venv\\Scripts\\python", "-m", "pip", "install", "-r", "requirements.txt"],
    check=True,
)
