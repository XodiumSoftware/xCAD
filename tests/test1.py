# ... (existing code remains the same)


class ModuleHandler(QWidget):
    # ... (existing code remains the same)

    def create_modules_from_matrix(self, matrix_index, matrix_margins):
        module_matrix_data = next(
            (data for data in MATRICES if data["index"] == matrix_index),
            None,
        )

        if module_matrix_data:
            module_matrix_pos = module_matrix_data.get("module_matrix_pos", [])
            layout = QGridLayout(self)
            layout.setContentsMargins(*self.setup_module_margins(matrix_margins))

            for row, row_modules in enumerate(module_matrix_pos):
                for column, module_args in enumerate(row_modules):
                    if isinstance(module_args, list):
                        # Handle the case when module_args contains a list of widgets.
                        module_container = self.setup_module_container(module_args)
                        layout.addLayout(module_container, row, column)
                    else:
                        (
                            module_layout_type,
                            module_type,
                            module_index,
                            module_margins,
                            module_alignment,
                            module_size_policy,
                        ) = module_args

                        module_container = self.setup_module_layout(module_layout_type)
                        module_container.setContentsMargins(
                            *self.setup_module_margins(module_margins)
                        )

                        if module_alignment is not None:
                            module_container.setAlignment(
                                self.setup_module_alignment(module_alignment)
                            )

                        module_data = self.setup_module_data(module_type, module_index)

                        if module_data:
                            if module_layout_type.startswith("Nested"):
                                # Handle the case when module_args represents a nested container.
                                nested_container_layout = (
                                    self.create_modules_from_nested_matrix(
                                        module_args[1]
                                    )
                                )
                                module_container.addLayout(nested_container_layout)
                            else:
                                module = self.setup_module_creation(
                                    module_type, module_data
                                )
                                if module:
                                    if module_size_policy is not None:
                                        (
                                            size_policy_x,
                                            size_policy_y,
                                        ) = self.setup_module_size_policy(
                                            module_size_policy
                                        )
                                        module.setSizePolicy(
                                            size_policy_x, size_policy_y
                                        )

                                    module_container.addWidget(module)
                                    layout.addLayout(module_container, row, column)

                                else:
                                    raise ValueError(
                                        f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                                    )
                        else:
                            raise ValueError(
                                f"{DEBUG_NAME}{module_type}_{module_index}: not found"
                            )

        else:
            raise ValueError(
                f"{DEBUG_NAME}Module index {matrix_index} not found in MODULE_MATRICES"
            )

    def create_modules_from_nested_matrix(self, nested_matrix_pos):
        # Recursive method to create nested containers with widgets.
        container_layout = QVBoxLayout()

        for nested_row_modules in nested_matrix_pos:
            nested_container = QVBoxLayout()

            for nested_module_args in nested_row_modules:
                (
                    module_layout_type,
                    module_type,
                    module_index,
                    module_margins,
                    module_alignment,
                    module_size_policy,
                ) = nested_module_args

                module_container = self.setup_module_layout(module_layout_type)
                module_container.setContentsMargins(
                    *self.setup_module_margins(module_margins)
                )

                if module_alignment is not None:
                    module_container.setAlignment(
                        self.setup_module_alignment(module_alignment)
                    )

                module_data = self.setup_module_data(module_type, module_index)

                if module_data:
                    module = self.setup_module_creation(module_type, module_data)
                    if module:
                        if module_size_policy is not None:
                            (
                                size_policy_x,
                                size_policy_y,
                            ) = self.setup_module_size_policy(module_size_policy)
                            module.setSizePolicy(size_policy_x, size_policy_y)

                        module_container.addWidget(module)
                        nested_container.addLayout(module_container)

                    else:
                        raise ValueError(
                            f'{DEBUG_NAME}"{module_type}" is not a valid module type'
                        )
                else:
                    raise ValueError(
                        f"{DEBUG_NAME}{module_type}_{module_index}: not found"
                    )

            container_layout.addLayout(nested_container)

        return container_layout


# ... (existing code remains the same)
