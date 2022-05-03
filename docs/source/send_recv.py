import numpy as np
import matplotlib.pyplot as plt

class Group(object):

    def __init__(self, pe):
        self.pe = pe
        self.a = np.array([0, 3*pe, 3*pe+1, 3*pe+2, 0])

    def __str__(self):
        astr = ["{}".format(q) for q in self.a]
        return " ".join(list(astr))

    def plot(self, up=False, down=False):
        shift = len(self.a) - 2
        for i in range(len(self.a)):

            if i == 0 or i == len(self.a)-1:
                c = "C1"
            else:
                c = "k"

            xl = shift*self.pe+i
            xr = shift*self.pe+0.8+i

            xc = 0.5*(xl+xr)
            yc = -1.2*self.pe

            plt.text(xc, yc + 0.1, "{}".format(self.a[i]), horizontalalignment="center", color=c)
            plt.plot([xl, xr], [yc, yc], color=c)

            if up and i == 1:
                plt.arrow(xc, yc+0.4, 0, 0.5, head_width=0.075, color="C0")

            if down and i == len(self.a)-2:
                plt.arrow(xc, yc-0.2, 0, -0.5, head_width=0.075, color="C0")


num_pe = 4
pes = []
for i in range(num_pe):
    pes.append(Group(i))

# fill ghost cells
for i in range(num_pe):
    if i > 0:
        pes[i].a[0] = pes[i-1].a[-2]
    if i < num_pe-1:
        pes[i].a[-1] = pes[i+1].a[1]

for pe in pes:
    print(pe)

for n, pe in enumerate(pes):
    up = True
    down = True
    if n == 0:
        up = False
    if n == len(pes)-1:
        down = False

    pe.plot(up=up, down=down)

plt.axis("off")
ax = plt.gca()
ax.set_aspect("equal", "datalim")

f = plt.gcf()
f.set_size_inches(8.0, 3.5)
plt.tight_layout()
plt.savefig("send_recv_diagram.png", dpi=150)





