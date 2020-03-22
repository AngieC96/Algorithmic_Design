#!/usr/bin/env bash

## qsub script.sh

####################################################################
#
#
# ==== PBS part (resource manager part) =====
#
# The following indicates the nuber of requested nodes
# The number of ppn (processes per node) remains fixed to 20
#PBS -l nodes=1:ppn=20
#
# Total amount of time for which resources are requested HH:MM:SS
#PBS -l walltime=12:00:00
#
# Name of the Job as it will appear in the queue (qstat -u $USER)
#PBS -N Strassen_square
#
# Name of the dedicated resources. You must uncomment this entry when running 
# outside the didicated hours. For possible queue names, see (man queues).
#PBS -q regular
#
# Message flags: send a message if the jobs (b)egins, (e)nds or (a)borts. 
#PBS -m bea
#
# ==== End of PBS part (resource manager part) =====
#
#
# ==== Modules part (load things) =====
#

#
# ==== End of Modules part (load things) =====
#
#
# ==== Info part (say things) =====
#
NCPU=`wc -l < $PBS_NODEFILE`
NNODES=`uniq $PBS_NODEFILE | wc -l`
NOW=`date +%H:%M-%a-%d/%b/%Y`
echo ------------------------------------------------------
echo 'This job is allocated on '$NCPU' cpu(s)'
echo 'Job is running on node(s): '
cat  $PBS_NODEFILE
echo ------------------------------------------------------
echo WORKINFO:
echo PBS: the job was submitted     $NOW
echo PBS: qsub is running on        $PBS_O_HOST
echo PBS: originating queue is      $PBS_O_QUEUE
echo PBS: executing queue is        $PBS_QUEUE
echo PBS: working directory is      $PBS_O_WORKDIR
echo PBS: current home directory is $PBS_O_HOME
echo ""
echo JOBINFO:
echo PBS: execution mode is    $PBS_ENVIRONMENT
echo PBS: job identifier is    $PBS_JOBID
echo PBS: job name is          $PBS_JOBNAME
echo ""
echo NODEINFO:
echo PBS: node file is         $PBS_NODEFILE
echo PBS: number of nodes is   $NNODES
echo PBS: number of cpu        $NCPU
echo ------------------------------------------------------
#
# ==== End of Info part (say things) =====

# Move to the working directory
cd $PBS_O_WORKDIR

# ==== JOB COMMANDS =====


./strassen_text.x > ./output.txt


# ==== END OF JOB COMMANDS =====


# Wait for processes, if any.
echo "Waiting for all the processes to finish..."
wait
