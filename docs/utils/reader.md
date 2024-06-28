---
description: A class that contains reader functions.
---

# ⚡ Reader

## "<mark style="color:orange;">file</mark>" method

{% code title="class Reader" overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    @staticmethod
    def file(path: Path) -> str: ...
        """Read a file.

        Args:
            path: The path to the file.
        """
```
{% endcode %}

## Usage

{% code overflow="wrap" lineNumbers="true" fullWidth="false" %}
```python
    from dalmatium import Utils

    Utils.read.file(...)
```
{% endcode %}

{% hint style="warning" %}
[<mark style="color:orange;">**If you have questions on why we are using**</mark>** **<mark style="color:red;">**"read"**</mark>** **<mark style="color:orange;">**instead of**</mark>** **<mark style="color:red;">**"Reader"**</mark><mark style="color:orange;">**, then click on me!**</mark>](../quick-start.md)
{% endhint %}
