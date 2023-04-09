import os
import sys


def get_plugin_folder():
    """Returns the path to the BricsCAD plugin folder."""
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
