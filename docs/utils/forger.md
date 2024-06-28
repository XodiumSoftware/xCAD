---
description: A class that contains forger functions.
---

# ⚡ Forger

## "<mark style="color:orange;">dir</mark>" method

{% code title="class Forger" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    @staticmethod
    def dir(
        path: Path,
        mode: int = 511,
        *,
        parents: bool = True,
        exist_ok: bool = True,
    ) -> Path: ...
        """Forge a directory if it does not exist.

        Args:
            path: The path to the directory.
            mode: The mode of the directory.
            parents: Whether to create parent directories.
            exist_ok: Whether to raise an error if the directory exists.

        Returns:
            The path to the directory.

        Raises:
            OSError: If the directory could not be created.
        """
```
{% endcode %}

## "<mark style="color:orange;">file</mark>" method

{% code title="class Forger" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    @staticmethod
    def file(
        path: Path,
        mode: int = 438,
        *,
        exist_ok: bool = True,
    ) -> Path: ...
        """Forge a file if it does not exist.

        Args:
            path: The path to the file.
            mode: The mode of the file.
            exist_ok: Whether to raise an error if the file exists.

        Returns:
            The path to the file.

        Raises:
            OSError: If the file could not be created.
        """
```
{% endcode %}

## Usage

{% code overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    from dalmatium import Utils

    Utils.forge.dir(...)
    Utils.forge.file(...)
```
{% endcode %}

{% hint style="warning" %}
[<mark style="color:orange;">**If you have questions on why we are using**</mark>** **<mark style="color:red;">**"forge"**</mark>** **<mark style="color:orange;">**instead of**</mark>** **<mark style="color:red;">**"Forger"**</mark><mark style="color:orange;">**, then click on me!**</mark>](../quick-start.md)
{% endhint %}
