import unittest
from typing import Any, Callable
from unittest.mock import call, patch

from AFCHandlers import UIHandler


class TestUIHandler(unittest.TestCase):
    def setUp(self):
        self.ui_handler = UIHandler()
        self.patchers = {
            "set_theme": patch("sv_ttk.set_theme"),
            "deiconify": patch.object(self.ui_handler, "deiconify"),
            "withdraw": patch.object(self.ui_handler, "withdraw"),
            "bind": patch.object(self.ui_handler, "bind"),
            "frame": patch("ttk.Frame"),
            "grid": patch.object(self.ui_handler, "grid"),
            "rowconfigure": patch.object(self.ui_handler, "rowconfigure"),
            "columnconfigure": patch.object(
                self.ui_handler, "columnconfigure"
            ),
        }
        self.mocks = {
            name: patcher.start() for name, patcher in self.patchers.items()
        }

    def tearDown(self):
        for patcher in self.patchers.values():
            patcher.stop()

    def test_theme_sets_ttk_theme(self):
        theme = "default"
        self.ui_handler.theme(theme)
        self.mocks["set_theme"].assert_called_once_with(theme)

    def test_visible_shows_ui(self):
        self.ui_handler.visible(True)
        self.mocks["deiconify"].assert_called_once()
        self.mocks["withdraw"].assert_not_called()

    def test_visible_hides_ui(self):
        self.ui_handler.visible(False)
        self.mocks["withdraw"].assert_called_once()
        self.mocks["deiconify"].assert_not_called()

    def test_events_binds_events(self):
        events: dict[str, Callable[[Any], None]] = {
            "<Control-w>": lambda _: self.ui_handler.quit(),
        }
        self.ui_handler.events(events)
        calls = [call(event, events[event]) for event in events]
        self.mocks["bind"].assert_has_calls(calls, any_order=False)


if __name__ == "__main__":
    unittest.main()
