from bbc.libs.bricscad import bricscadapi


def draw_line_between_two_points(start_point, end_point):
    # Create a new line entity
    line = bricscadapi.Line(start_point, end_point)

    # Add the line entity to the current space
    bricscadapi.add_line(line)

    # Refresh the display
    bricscadapi.redraw()


# Register the "MyCommand" command with BricsCAD
bricscadapi.add_command("MyCommand", draw_line_between_two_points)
