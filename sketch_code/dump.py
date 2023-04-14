def create_input_fields2(self):
        """
        This function creates input fields with labels and placeholders in a QGridLayout.
        """
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1) in enumerate(
            zip(
                TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC0, TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC2
            )
        ):
            label0 = QLabel(desc0, self)
            input = QLineEdit(self)
            label1 = QLabel(desc1, self)

            self.labels.extend([label0, label1])
            self.inputs.append(input)

            input_validate = QIntValidator()
            input_validate.setBottom(0)

            input.setValidator(input_validate)

            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

            input.setPlaceholderText(TFCC_UI_GROUPBOX_INPUT_FIELDS_DESC1[i])

    @staticmethod
    def input_validator2(
        text_input: str, pos: int, obj_num: int
    ) -> tuple[QValidator.State, str, int]:
        if obj_num in [1, 2, 4, 5, 7]:
            if text_input == "":
                return QValidator.State.Intermediate, text_input, pos
            try:
                value = int(text_input)
                if value >= 0:
                    return QValidator.State.Acceptable, text_input, pos
                else:
                    return QValidator.State.Invalid, text_input, pos
            except ValueError:
                return QValidator.State.Invalid, text_input, pos
        elif obj_num in [3, 6]:
            if text_input.isalpha() or text_input == "":
                return QValidator.State.Acceptable, text_input, pos
            else:
                return QValidator.State.Invalid, text_input, pos
        else:
            return QValidator.State.Invalid, text_input, pos