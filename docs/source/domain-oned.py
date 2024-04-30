import matplotlib.pyplot as plt

def draw_box(ax, ll, uu, nx, ny, gridColor="0.5", ng=0):

    # draw the frame
    ax.plot([ll[0], ll[0], uu[0], uu[0], ll[0]],
            [ll[1], uu[1], uu[1], ll[1], ll[1]], color="k", lw=2)

    # draw the x grid lines
    dx = (uu[0] - ll[0])/nx
    for n in range(1, nx):
        ax.plot([ll[0]+n*dx, ll[0]+n*dx],
                [ll[1], uu[1]], color=gridColor, ls=":", lw=1)

    # draw the y grid lines
    dy = (uu[1] - ll[1])/ny
    for n in range(1, ny):
        ax.plot([ll[0], uu[0]],
                [ll[1]+n*dy, ll[1]+n*dy], color=gridColor, ls=":", lw=1)

    # ghostcells?
    if ng > 0:
        xmin = ll[0]-ng*dx
        xmax = uu[0]+ng*dx
        ymin = ll[1]-ng*dy
        ymax = uu[1]+ng*dy
        ax.plot([xmin, xmin, xmax, xmax, xmin],
                [ymin, ymax, ymax, ymin, ymin],
                ls="--", color="r")



fig, ax = plt.subplots()

draw_box(ax, [0., 0.], [1., 2.], 5, 10)
draw_box(ax, [1., 0.], [2., 2.], 5, 10, ng=1)
draw_box(ax, [2., 0.], [3., 2.], 5, 10)

ax.set_xlim(-0.25, 3.25)
ax.set_ylim(-0.25, 2.25)

ax.set_aspect("equal", "datalim")
ax.set_axis_off()

ax.arrow(0.125, -0.125, 0.33, 0,
         shape="full", head_width=0.04, head_length=0.06,
         lw=1, width=0.005,
         facecolor="k",
         length_includes_head=True, zorder=100)
ax.text(0.55, -0.125, "i", verticalalignment="center")


ax.arrow(-0.125, 0.125, 0, 0.33,
         shape="full", head_width=0.04, head_length=0.06,
         lw=1, width=0.005,
         facecolor="k",
         length_includes_head=True, zorder=100)
ax.text(-0.125, 0.55, "j", horizontalalignment="center")


fig.set_size_inches(6.5, 4.25)
fig.tight_layout()

fig.savefig("domain-oned.png", bbox_inches="tight")
