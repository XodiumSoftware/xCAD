from enum import Enum


class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3


# Accessing enum members
print(Color.RED)  # Color.RED
print(Color.RED.name)  # RED
print(Color.RED.value)  # 1

# Iterating through enum members
for color in Color:
    print(color)
    print(color.name)
    print(color.value)

# Comparison between enum members
print(Color.RED is Color.BLUE)  # False
print(Color.RED is not Color.BLUE)  # True
