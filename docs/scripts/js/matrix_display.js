/**
 * Represents a class for managing and displaying matrices along with their properties.
 */
class MatrixDisplay {
  /**
   * Creates an instance of MatrixDisplay.
   */
  constructor (matrices) {
    this.matrices = matrices
    this.constantsEditorContent = document.getElementById(
      'matrix_editor_content'
    )
    this.matrixSelect = document.getElementById('matrixSelect')
    this.matrixSelect.addEventListener(
      'change',
      this.handleMatrixChange.bind(this)
    )

    this.populateMatrixSelect()
    this.displayMatrix(this.matrices[0].index)
  }

  /**
   * Creates an instance of MatrixDisplay.
   */
  populateMatrixSelect () {
    this.matrices.forEach((matrix) => {
      const option = document.createElement('option')
      option.value = matrix.index
      option.textContent = `Matrix ${matrix.index}`
      this.matrixSelect.appendChild(option)
    })
  }

  /**
   * Event handler for matrix selection change.
   */
  handleMatrixChange (event) {
    const selectedMatrixIndex = parseInt(event.target.value, 10)
    this.displayMatrix(selectedMatrixIndex)
  }

  /**
   * Generates HTML content for displaying a matrix's properties and elements.
   */
  generateMatrixContent (matrix) {
    let content = `<div class="matrix">
                        <h3>Matrix Index: ${matrix.index}</h3>`

    matrix.module_matrix_pos.forEach((row) => {
      content += "<div class='matrix-row'>"

      row.forEach(
        ([layout, widget, widgetIndex, margins, alignment, sizePolicy]) => {
          content += `<div class='matrix-column'>
                                <p class='module-title'>Element</p>
                                <hr>
                                <table>
                                    <tr><td>Layout:</td><td>${this.generateLayoutDropdown(
                                      layout
                                    )}</td></tr>
                                    <tr><td>Module Type (Widget):</td><td>${this.generateModuleTypeDropdown(
                                      widget
                                    )}</td></tr>
                                    <tr><td>Module Index:</td><td><input type="number" value="${widgetIndex}" min="0" /></td></tr>
                                    <tr><td>Margins:</td><td>${this.generateMarginsInputFields(
                                      margins
                                    )}</td></tr>
                                    <tr><td>Alignment:</td><td>${this.generateAlignmentDropdown(
                                      alignment
                                    )}</td></tr>
                                    <tr><td>Size Policy:</td><td>${this.generateSizePolicyDropdowns(
                                      sizePolicy
                                    )}</td></tr>
                                </table>
                            </div>`
        }
      )

      content += '</div>'
    })

    content += '</div>'
    return content
  }

  /**
   * Generates HTML input fields for margin values.
   */
  generateMarginsInputFields (margins) {
    const [x, y, z, w] = margins
    return `
            Left: <input type="number" value="${x}" min="0" />
            Top: <input type="number" value="${y}" min="0" />
            Right: <input type="number" value="${z}" min="0" />
            Bottom: <input type="number" value="${w}" min="0" />
        `
  }

  /**
   * Generates a dropdown for layout selection.
   */
  generateLayoutDropdown (selectedLayout) {
    return this.generateDropdown(selectedLayout, [
      'VBox',
      'HBox',
      'Grid',
      'Form'
    ])
  }

  /**
   * Generates a dropdown for layout selection.
   */
  generateModuleTypeDropdown (selectedModuleType) {
    return this.generateDropdown(
      selectedModuleType,
      [
        'Label',
        'Checkbox',
        'SpinBox',
        'InputField',
        'Button',
        'GraphicsView',
        'TableView'
      ],
      'width: 100%'
    )
  }

  /**
   * Generates a dropdown for alignment selection.
   */
  generateAlignmentDropdown (selectedAlignment) {
    return this.generateDropdown(selectedAlignment, [
      'AlignLeading',
      'AlignLeft',
      'AlignRight',
      'AlignTrailing',
      'AlignHCenter',
      'AlignVCenter',
      'AlignJustify',
      'AlignAbsolute',
      'AlignHorizontalMask',
      'AlignTop',
      'AlignBottom',
      'AlignCenter',
      'AlignBaseline',
      'AlignVerticalMask'
    ])
  }

  /**
   * Generates dropdowns for size policy selection.
   */
  generateSizePolicyDropdowns (sizePolicy) {
    let dropdownsHTML = ''

    sizePolicy.forEach((policy) => {
      dropdownsHTML += `
              <div class="size-policy-dropdown">
                  ${this.generateDropdown(policy, [
                    'SizeMinimum',
                    'SizeMaximum',
                    'SizeFixed',
                    'SizePreferred',
                    'SizeExpanding',
                    'SizeMinimumExpanding',
                    'SizeIgnored'
                  ])}
              </div>
          `
    })

    return `<div class="size-policy-container">${dropdownsHTML}</div>`
  }

  /**
   * Generates a dropdown with the specified options and selected values.
   */
  generateDropdown (selectedValues, options, style = '') {
    let dropdownHTML = `<select style="${style}">`

    options.forEach((option) => {
      const isSelected = selectedValues.includes(option) ? 'selected' : ''
      dropdownHTML += `<option value="${option}" ${isSelected}>${option}</option>`
    })

    dropdownHTML += '</select>'
    return dropdownHTML
  }

  /**
   * Displays a matrix's properties and elements.
   */
  displayMatrix (matrixIndex) {
    const selectedMatrix = this.matrices.find(
      (matrix) => matrix.index === matrixIndex
    )

    if (selectedMatrix) {
      const content = this.generateMatrixContent(selectedMatrix)
      this.constantsEditorContent.innerHTML = content
    } else {
      this.constantsEditorContent.innerHTML = '<p>Matrix not found.</p>'
    }
  }
}

const matrices = [
  {
    index: 0,
    module_matrix_pos: [
      [
        [
          'VBox',
          'Button',
          0,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeExpanding', 'SizeExpanding']
        ]
      ],
      [
        [
          'VBox',
          'Label',
          0,
          [0, 0, 0, 0],
          'AlignBottom',
          ['SizeMinimum', 'SizeMinimum']
        ]
      ]
    ]
  },
  {
    index: 1,
    module_matrix_pos: [
      [
        [
          'VBox',
          'TableView',
          1,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeExpanding', 'SizeExpanding']
        ],
        [
          [
            'VBox',
            'GraphicsView',
            0,
            [0, 0, 0, 0],
            'AlignCenter',
            ['SizeExpanding', 'SizeExpanding']
          ]
        ]
      ],
      [
        [
          'VBox',
          'Button',
          2,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeMinimum', 'SizeMinimum']
        ],
        [
          'VBox',
          'Button',
          3,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeMinimum', 'SizeMinimum']
        ],
        [
          'VBox',
          'Button',
          4,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeMinimum', 'SizeMinimum']
        ]
      ],
      [
        [
          'VBox',
          'Button',
          5,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeMinimum', 'SizeMinimum']
        ],
        [
          'VBox',
          'Button',
          1,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeMinimum', 'SizeMinimum']
        ]
      ],
      [
        [
          'VBox',
          'Label',
          0,
          [0, 0, 0, 0],
          'AlignCenter',
          ['SizeMinimum', 'SizeMinimum']
        ]
      ]
    ]
  }
]

new MatrixDisplay(matrices)
