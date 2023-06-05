from PySide6.QtCore import QObject, Signal


class SignalHandler(QObject):
    def __init__(self):
        super().__init__()
        self.signals = {}

    def register_signal(self, signal_name):
        signal = Signal()
        setattr(self, signal_name, signal)
        self.signals[signal_name] = signal

    def connect_slot(self, signal_name, slot):
        signal = self.signals.get(signal_name)
        if signal:
            signal.connect(slot)
