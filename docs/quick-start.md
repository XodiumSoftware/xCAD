---
layout:
  title:
    visible: true
  description:
    visible: false
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: true
---

# 🏃 Quick Start

{% hint style="warning" %}
<mark style="color:orange;">**This library**</mark> uses a certain structure to make it easier readable at accessing the methods, we do this by assigning a variable to each class like this:

{% code overflow="wrap" lineNumbers="true" fullWidth="true" %}
```python
class Utils:
    """A class that contains utility functions."""

    (
        db,
        forge,
        read,
        wrap,
    ) = (
        Database,
        Forger,
        Reader,
        Wrapper,
    )
```
{% endcode %}

<mark style="color:orange;">**So we kindly ask of you to keep using the structure for everyone's convenience!**</mark>
{% endhint %}

## Install the library

The best way how to use one of our official libraries:

{% tabs %}
{% tab title="Python" %}
```bash
# Install via pip
pip install --upgrade dalmatium
```
{% endtab %}
{% endtabs %}

{% hint style="info" %}
<mark style="color:blue;">Y</mark><mark style="color:blue;">**ou can**</mark> use the buttons below to navigate <mark style="color:purple;">faster</mark> to a previous or next page!
{% endhint %}
