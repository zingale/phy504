by default, this will look for files with the prefix plt*, and
then do the anaylsis on them -- currently the analysis is just
'echo'


To generate some fake data, do:

```
for i in $(seq -w 1 1 10)
do
    touch plt$i
done
```