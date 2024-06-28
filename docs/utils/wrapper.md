---
description: A class that contains wrapper functions.
---

# ⚡ Wrapper

## "<mark style="color:purple;">\_\_init\_\_</mark>" method

{% code title="class Wrapper" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    def __init__(self: "Wrapper", path: Path) -> None: ...
        """Initializes the .so library.

        Args:
            path: The path to the .so library.

        Raises:
            OSError: If the .so library could not be initialized.
        """
```
{% endcode %}

## "<mark style="color:purple;">\_\_</mark><mark style="color:purple;">**getattr\_\_**</mark>" method

{% code title="class Wrapper" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    def __getattr__(self: "Wrapper", func: str) -> Callable[..., object]: ...
        """Gets the function from the library.

        Args:
            func: The name of the function.

        Returns:
            The function.

        Raises:
            AttributeError: If the function could not be found.
        """
```
{% endcode %}

## "<mark style="color:purple;">\_\_</mark><mark style="color:purple;">**dir\_\_**</mark>" method

{% code title="class Wrapper" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    def __dir__(self: "Wrapper") -> list[str]: ...
        """Gets the functions in the library.

        Args:
            None

        Returns:
            list[str]: The functions in the library.

        Raises:
            Exception: If the functions could not be retrieved.
        """
```
{% endcode %}

## Usage

{% code overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    from dalmatium import Utils

    Utils.wrap.__getattr__(...)
    Utils.wrap.__dir__(...)
```
{% endcode %}

{% hint style="warning" %}
[<mark style="color:orange;">**If you have questions on why we are using**</mark>** **<mark style="color:red;">**"wrap"**</mark>** **<mark style="color:orange;">**instead of**</mark>** **<mark style="color:red;">**"Wrapper"**</mark><mark style="color:orange;">**, then click on me!**</mark>](../quick-start.md)
{% endhint %}
