[![CI Epitech Project - Octopus](https://github.com/MyEpitech/B-CCP-400-PAR-4-1-theplazza-clement.fernandes/actions/workflows/main.yml/badge.svg?branch=master)](https://github.com/MyEpitech/B-CCP-400-PAR-4-1-theplazza-clement.fernandes/actions/workflows/main.yml)

# Plazza :pizza:

## $\color{green}{Grade: B}$

## About the project

The purpose of this project is to make a **simulation of a pizzeria**, which is composed of the reception that accepts new commands, of several kitchens, themselves with several cooks, themselves cooking several pizzas at the same time.

---

## Getting Started

You just have to clone the repository and follow the instructions below.

### Prerequisites

Clone the repositorie

```bash
git clone https://github.com/Clement-Fernandes/Plazza.git
```

#### Execute the project

```bash
$ cd Plazza
$ make
$ ./plazza 2 5 2000
```

#### How to order a pizza ?

While the plazza is running you can order a pizza thanks to the textbox at the top of the window.

The order format is `[PIZZA NAME] [SIZE] x[QUANTITY]`, for example : `americana L x17`

You can do multiple order at the same time with `;` : `americana XXL x15 ; fantasia L x10` In multiple order, if there is an invalid pizza in the line, it will be ignored.

When your order is sent, each oppened window shows you a kitchen. You can directly see the progression of the pizza baking !

If a kitchen doesn't receive an order, it will close after **5 seconds**.

**Thank you for your interest in this project.** :smile:
