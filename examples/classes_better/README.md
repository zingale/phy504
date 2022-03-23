As written, this has a method to return by value a Planet object.

If we instead use `solar_system_find.H`, it has a `find_planet`
function that will return an iterator to a planet in our vector, which
can then be dereferenced.

