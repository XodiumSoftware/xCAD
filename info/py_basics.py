class Foo:
    """A class to demonstrate the difference between class attributes and properties."""

    attribute_1 = []
    attribute_2 = 1

    def __init__(self) -> None:
        self.property = 3


a = Foo()
b = Foo()

a.attribute_1.append(1)
# this appends the value to the attribute of the class
# (a list is a pointer to a place in memory)
# so it modifies everywhere the class is called
# because we're pointing at the class
print("Attribute 1:")
print(a.attribute_1)
print(b.attribute_1)

a.attribute_2 += 1
# while this is pointing at a local instance and therefore it only modifies locally
print("Attribute 2:")
print(a.attribute_2)
print(b.attribute_2)

a.property += 1
# properties will always modify locally
# because properties are related to the instances
# and a and b are two different instances of the same object
print("Property:")
print(a.property)
print(b.property)


# RUN THE CODE TO FIND OUT !!!


"""
More advanced explanation:

In summary, class attributes are static attributes that are defined
directly within the class and are shared by all instances of the class,
while properties are dynamic attributes that are computed using getter
and setter methods and provide additional control and validation
over attribute access and modification.
"""
