import numpy as np
from mutate import update

a = np.arange(12, dtype=np.float64).reshape(4, 3)

update(a)

print(a)
