#!/bin/bash

# run a bunch of single-processor analysis jobs in parallel.  Lock
# files are used to keep track of how many processors are in use at
# any given time -- this allows for jobs of varying length to be run
# together.

#----------------------------------------------------------------------------
# user modifiable variables:

# number of parallel tasks to run
NCPUS=4

# set the prefix of the datafile to process
data_prefix=plt

# set the full name of the analysis routines (must be in the path)
analysis=echo

# Number of seconds to sleep before checking again.
N=60


#----------------------------------------------------------------------------
# the processing functions
function process_files
{

    # the argument $1 is the name of the datafile

    echo "working on " $1
    root=$(basename $1)
    echo $1 > _process.$root

    if [ -f $1 ]; then

        # do processing
        ${analysis} $1   #>> /dev/null

        # this sleep line is not necessary if the analysis takes any
        # measurable amount of time
        sleep 30

    fi   # end test of whether datafile is a file (as it should be)

    rm -f _process.$root
}



#----------------------------------------------------------------------------
# The function freecpus looks counts the _process.XX files to determine how many
# files we are currently processing.  If we are processing < NCPUS, return 1 to
# indicate that there are free CPUs available to do more processing.
function freecpus
{
    num=$(ls -l _process.* 2> /dev/null | wc -l)

    if [ $num -lt $NCPUS ]; then
        return 1
    else
        return 0
    fi
}


#----------------------------------------------------------------------------
# the main loop

# We process NCPUS files at a time.  We loop over files, waiting for free CPUs.
# When a CPU becomes available, we launch the processing job in the background,
# and move to the next file, again waiting for an available CPU.

filelist=$(find . -maxdepth 1 -type f -name "${data_prefix}*" -print | sort)

for file in ${filelist}
do

    # wait for available CPUS
    freecpus
    while [ $? -eq 0 ]
    do
        sleep 1
        freecpus
    done

    process_files ${file} &

    sleep 1
done
