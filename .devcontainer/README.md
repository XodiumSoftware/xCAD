# Docker Configuration for GUI Applications

This guide provides instructions on how to configure Docker to run GUI applications in a `devcontainer`. The steps vary depending on your operating system.

## Windows

1. Install VcXsrv Windows X Server from `https://sourceforge.net/projects/vcxsrv/`.
2. Run VcXsrv.
3. In the `devcontainer.json` use the `"runArgs"` for your specific os.
4. Rebuild the container.

## Linux

1. Give Docker access to the display by exec the following in the host console: `sudo xhost +local:docker`.
2. In the `devcontainer.json` use the `"runArgs"` for your specific os.
3. Rebuild the container.

## MacOS

1. Install XQuartz from `https://www.xquartz.org/`.
2. Open XQuartz and then select `Preferences`.
3. Go to the `Security` tab and ensure `Allow connections from network clients` is checked.
4. Restart your machine to ensure the changes take effect.
5. In the `devcontainer.json` use the `"runArgs"` for your specific os.
6. Rebuild the container.
