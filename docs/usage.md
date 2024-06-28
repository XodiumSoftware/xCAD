---
description: A class that contains database functions.
---

# 💡 Usage

## "<mark style="color:purple;">\_\_init\_\_</mark>" method

{% code title="class Database" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    def __init__(self: "Database", path: Path) -> None: ...
        """Initialize the class.

        Args:
            path: The path to the database file.
        """
```
{% endcode %}

## "<mark style="color:orange;">db\_session</mark>" method

{% code title="class Database" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    @contextmanager
    def db_session(self: "Database") -> Iterator[Session]: ...
        """Context manager for a database session.

        Returns:
            The database session.
        """
```
{% endcode %}
