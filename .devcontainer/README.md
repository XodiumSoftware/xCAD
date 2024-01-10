# Docker Configuration for GUI Applications

This guide provides instructions on how to configure Docker to run GUI applications in a `devcontainer`. The steps vary depending on your operating system.

## Windows

1. Install VcXsrv Windows X Server from `https://sourceforge.net/projects/vcxsrv/`.
2. Run VcXsrv.
3. In the `devcontainer.json`, replace the args in the list of `"runArgs": [...]` with the following:
   `"--net=host", "-v=C:/Users/admin/.Xauthority:/tmp/.Xauthority",` (replace the path if necessary)
   `"-e=DISPLAY=host.docker.internal:0", "-e=XAUTHORITY=/tmp/.Xauthority"`.
4. Rebuild the container.

## Linux

1. In the `devcontainer.json`, replace the args in the list of `"runArgs": [...]` with the following:
   `"--net=host", "-v=/tmp/.X11-unix:/tmp/.X11-unix"` (replace the path if necessary).
2. Give Docker access to the display by executing `sudo xhost +local:docker` in the Linux terminal.
3. Rebuild the container.

## MacOS

1. Install XQuartz from `https://www.xquartz.org/`.
2. Open XQuartz and then select `Preferences`.
3. Go to the `Security` tab and ensure `Allow connections from network clients` is checked.
4. Restart your machine to ensure the changes take effect.
5. In the `devcontainer.json`, replace the args in the list of `"runArgs": [...]` with the following:
   `"--net=host", "-e=DISPLAY=host.docker.internal:0", "-v=/tmp/.X11-unix:/tmp/.X11-unix"`
6. Rebuild the container.

Please note that the `-v` argument may need to be adjusted based on your specific setup. This is a general guide and may not work for all configurations. Always ensure to follow best security practices when modifying Docker configurations.
