export workdir=/afs/cern.ch/user/m/mzhou/work/private/myttHAna

bsub -q 1nd '' python $workdir/util/RunmySkim.py tth ''
bsub -q 1nd '' python $workdir/util/RunmySkim.py ttV ''
bsub -q 1nd '' python $workdir/util/RunmySkim.py ttbar ''
bsub -q 1nd '' python $workdir/util/RunmySkim.py rare ''
bsub -q 1nd '' python $workdir/util/RunmySkim.py diboson ''
