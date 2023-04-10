import os
import sys


def get_plugin_folder():
    """
    This function returns the path to the BricsCAD plugin folder based on the user's operating system.
    :return: the path to the BricsCAD plugin folder based on the operating system. If the operating
    system is Windows, it returns the path to the BricsCAD folder in the APPDATA directory. If the
    operating system is Linux, it returns the path to the BricsCAD folder in the .config directory in
    the user's home directory. If the operating system is macOS, it returns the
    """
    if sys.platform.startswith('win'):
        # Windows
        appdata = os.getenv('APPDATA')
        if appdata:
            return os.path.join(appdata, 'Bricsys', 'BricsCAD')
        else:
            return ''
    elif sys.platform.startswith('linux'):
        # Linux
        return os.path.join(
            os.getenv('HOME'), '.config', 'Bricsys', 'BricsCAD')  # type: ignore
    elif sys.platform.startswith('darwin'):
        # macOS
        return os.path.join(
            os.getenv('HOME'), 'Library', 'Application Support', 'Bricsys', 'BricsCAD')  # type: ignore
    else:
        # Unsupported platform
        return ''


plugin_folder = os.path.join(get_plugin_folder(), 'Support', 'Plugins')
