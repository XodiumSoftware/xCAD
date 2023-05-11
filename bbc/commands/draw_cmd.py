from bbc.libs import bricscad


def draw_line_between_two_points(start_point, end_point):
    # Create a new line entity
    line = bricscad.Line(start_point, end_point)

    # Add the line entity to the current space
    bricscad.add_line(line)

    # Refresh the display
    bricscad.redraw()


# Register the "MyCommand" command with BricsCAD
bricscad.add_command("MyCommand", draw_line_between_two_points)
