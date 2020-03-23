# PHQ-9 test implemented in UCBLogo

The PHQ-9 is a [self administered test to help diagnose depression](https://en.wikipedia.org/wiki/PHQ-9).  It's used a lot in the NHS (indeed I must have filled out hundreds for the NHS at this point).  Obviously I am not a medical doctor and if you score consistently high you should contact a GP immediately.

To run, install UCBLogo, change to the `logo` subdirectory and then run:

```
ucblogo runphq9.lgo
```

Alternatively, from within UCBLogo you can run:

```
load "phq9logo.lgo
run_phq9
```

There's also a fledgling C version in `c`.  Compile it with your C compiler and run it, e.g. for `gcc` on Linux:

```
gcc -o phq9.exe phq9.c
./phq9.exe
```

The copyright of the questions is owned by Pfizer who have kindly [released the questions freely for use without charge or copyright restriction](http://press.pfizer.com/press-release/pfizer-offer-free-public-access-mental-health-assessment-tools-improve-diagnosis-and-p).  Thanks Pfizer!
