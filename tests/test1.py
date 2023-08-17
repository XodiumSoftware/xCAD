import matplotlib.pyplot as plt


def draw_timber_frame_wall(
    width_mm, height_mm, stud_spacing_mm, stud_thickness_mm, stud_height_mm
):
    fig, ax = plt.subplots()
    ax.set_aspect("equal")

    width_m = width_mm / 1000
    height_m = height_mm / 1000
    stud_spacing_m = stud_spacing_mm / 1000
    stud_thickness_m = stud_thickness_mm / 1000
    stud_height_m = stud_height_mm / 1000

    plt.plot([0, width_m, width_m, 0, 0], [0, 0, height_m, height_m, 0], color="black")

    num_studs = int(width_mm // stud_spacing_mm)
    for i in range(1, num_studs):
        x = i * stud_spacing_m
        plt.plot([x, x], [0, height_m], color="black")
        plt.plot(
            [x - stud_thickness_m / 2, x + stud_thickness_m / 2],
            [0, 0],
            color="black",
            linewidth=1,
        )
        plt.plot(
            [x - stud_thickness_m / 2, x + stud_thickness_m / 2],
            [stud_height_m, stud_height_m],
            color="black",
            linewidth=1,
        )
        plt.plot(
            [x - stud_thickness_m / 2, x - stud_thickness_m / 2],
            [0, stud_height_m],
            color="black",
            linewidth=1,
        )
        plt.plot(
            [x + stud_thickness_m / 2, x + stud_thickness_m / 2],
            [0, stud_height_m],
            color="black",
            linewidth=1,
        )

        plt.fill(
            [
                x - stud_thickness_m / 2,
                x + stud_thickness_m / 2,
                x + stud_thickness_m / 2,
                x - stud_thickness_m / 2,
            ],
            [0, 0, stud_height_m, stud_height_m],
            color="#ebd3b0",
            alpha=0.5,
        )

    plt.plot([0, width_m], [height_m / 2, height_m / 2], color="black")

    plt.title("Timber Frame Wall")
    plt.xlabel("Width (mm)")
    plt.ylabel("Height (mm)")
    plt.grid(True)
    plt.show()


wall_width_mm = 6000
wall_height_mm = 3000
stud_spacing_mm = 600
stud_thickness_mm = 100
stud_height_mm = 2400

draw_timber_frame_wall(
    wall_width_mm, wall_height_mm, stud_spacing_mm, stud_thickness_mm, stud_height_mm
)
