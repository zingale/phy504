*******************
Monte Carlo Methods
*******************

Monte Carlo methods involve using random numbers to produce different
realizations of a system and then building up statistics.


Pseudo-random numbers
=====================

Generally, producing truly random numbers is hard and we most often
use *pseudo-random* numbers.  These should have the following properties:

* The are fast to generate

* Each number is not correlated with the one that came before it

* They uniformly sample the range of interest (usually :math:`[0, 1)`)


Example: computing :math:`\pi`
==============================

