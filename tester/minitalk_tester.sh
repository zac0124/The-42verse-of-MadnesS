#!/bin/bash

###################################################
################# Minitalk Tester #################

echo -e "\n\033[1;34m========= MINITALK TESTER =========\033[0m\n"

# Correct paths if needed
minitalk_path="../"

results_path=results/
client_file=results/client.out.txt
server_file=results/server.out.txt
error_file=results/error.log
KO="[\033[31mKO\033[0m]"
OK="[\033[32mOK\033[0m]"
ERROR="[\033[33mERROR\033[0m]"

rm -rf $results_path 2> /dev/null
mkdir $results_path 2> /dev/null

###################################################
################### Compilation ###################

cd $minitalk_path
make re > /dev/null 2> /dev/null

# check if a program have been correctly creates

test_compile() {
    ls $1 > /dev/null 2> /dev/null
    if [ $? -eq 0 ]
    then
        echo -e "$1 \033[32m✔\033[0m"
    else
        echo -e "$1 \033[31mx\033[0m"
        echo -e "Compilation $KO\n"
        echo -e "\033[1mMinitalk failed ❌\033[0m\n"
        make fclean > /dev/null 2> /dev/null
        cd $tester_folder
        exit 1
    fi
}

test_compile client
test_compile server
echo ""

cd - > /dev/null 2> /dev/null

###################################################
#################### Execution ####################

# Execution of server

$minitalk_path/server > $server_file & server_pid=$!
sleep 1

# Check if the string has been received by the server

check_string(){
    cat $server_file | grep "$@" > /dev/null 2> /dev/null
    ret=$?
    if [ $ret -eq 1 ]
    then
        test_ok=1
    elif [ $ret -eq 2 ]
    then
        test_ok=2
    else
        test_ok=0
    fi
}

# Execute client and check the transmission

tester_ok=0

test_transmission() {
    # test_ok=0
    $minitalk_path/client $server_pid "$@" > $client_file 2>> $client_file
    check_string "$@"
    if [ $test_ok -eq 0 ]
    then
        echo -en $OK
    elif [ $test_ok -eq 1 ]
    then
        tester_ok=1
        echo -en $KO
    else
        echo -en $ERROR
    fi
}

###################################################
###################### Tests ######################

# Manual test
# Usage:./minitalk_tester.sh [string to pass]

if [ $# -ne 0 ]
then
    echo -e "\t\033[2m## Client output ##\033[0m"
    str="$@"
    $minitalk_path/client $server_pid "$str"
    kill $server_pid 2> /dev/null
    wait $server_pid 2> /dev/null
    echo -e "\n\t\033[2m## Server output ##\033[0m"
    cat $server_file
    len=${#str}
    echo -e "\n____________________________________"
    echo -e "\nstring size = $len\n"
    rm -rf $results_path 2> /dev/null
    cd $minitalk_path
    make fclean > /dev/null 2> /dev/null
    exit 0 2> /dev/null
fi

echo -e "\t\033[2m## Tests ##\033[0m\n"

# Tests of 10 characters

echo "10 characters:"

test_transmission "Hello World"
test_transmission "0123456789"
test_transmission "qwertyuiop"
test_transmission "zxcvbnm,./"

echo -e "\n"

# Tests of 100 characters

echo "100 characters:"

test_transmission "Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, to"
test_transmission "The quick, brown fox jumps over a lazy dog. DJs flock by when MTV ax quiz prog. Junk MTV quiz graced"
test_transmission "Li Europan lingues es membres del sam familie. Lor separat existentie es un myth. Por scientie, musi"
test_transmission "A wonderful serenity has taken possession of my entire soul, like these sweet mornings of spring whi"

echo -e "\n"

# Tests of 1000 characters

echo "1000 characters:"

test_transmission "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. \
Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec \
quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec \
pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, \
venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. \
Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat \
vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra \
nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur \
ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, \
sem quam semper libero, sit amet adipiscing sem neque sed ipsum. N"

test_transmission "One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his \
bed into a horrible vermin. He lay on his armour-like back, and if he lifted his head a little he could see \
his brown belly, slightly domed and divided by arches into stiff sections. The bedding was hardly able to cover \
it and seemed ready to slide off any moment. His many legs, pitifully thin compared with the size of the rest \
of him, waved about helplessly as he looked. \"What's happened to me?\" he thought. It wasn't a dream. His room, \
a proper human room although a little too small, lay peacefully between its four familiar walls. A collection of \
textile samples lay spread out on the table - Samsa was a travelling salesman - and above it there hung a picture \
that he had recently cut out of an illustrated magazine and housed in a nice, gilded frame. It showed a lady fitted \
out with a fur hat and fur boa who sat upright, raising a heavy fur muff that covered the whole of her lower arm towards t"

test_transmission "But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and \
I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, \
the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but \
because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful. Nor \
again is there anyone who loves or pursues or desires to obtain pain of itself, because it is pain, but because occasionally \
circumstances occur in which toil and pain can procure him some great pleasure. To take a trivial example, which of us \
ever undertakes laborious physical exercise, except to obtain some advantage from it? But who has any right to find fault \
with a man who chooses to enjoy a pleasure that has no annoying consequences, or one who avoids a pain that produces no \
resultant pleasure? On the other hand, we denounc"

test_transmission "The European languages are members of the same family. Their separate existence is a myth. For science, music, \
sport, etc, Europe uses the same vocabulary. The languages only differ in their grammar, their pronunciation and their \
most common words. Everyone realizes why a new common language would be desirable: one could refuse to pay expensive \
translators. To achieve this, it would be necessary to have uniform grammar, pronunciation and more common words. If \
several languages coalesce, the grammar of the resulting language is more simple and regular than that of the individual \
languages. The new common language will be more simple and regular than the existing European languages. It will be as \
simple as Occidental; in fact, it will be Occidental. To an English person, it will seem like simplified English, as a \
skeptical Cambridge friend of mine told me what Occidental is. The European languages are members of the same family. \
Their separate existence is a myth. For science, music, spo"

echo -e "\n"

# Test of a big string

bigstr=`cat bigTest.txt`
len=${#bigstr}
echo "$len characters:"
$minitalk_path/client $server_pid "$bigstr" > $client_file 2>> $client_file
check_string "$bigstr"
if [ $test_ok -eq 0 ]
then
    echo -e $OK
elif [ $test_ok -eq 1 ]
then
    echo -e $KO
    tester_ok=1
else
    echo -e $ERROR
fi
echo ""

###################################################
######################## END ######################

# Stop the server

kill $server_pid 2> /dev/null
wait $server_pid 2> /dev/null

# Display result ans clean up

if [ $tester_ok -ne 0 ]
then
    echo -e "\033[1mMinitalk failed ❌\033[0m"
    echo -e "Check \033[4m$server_file\033[0m\n"
else
    echo -e "\033[1mMinitalk succeed ✅\033[0m\n"
    rm -rf $results_path 2> /dev/null
    cd $minitalk_path
    make fclean > /dev/null 2> /dev/null
    cd - > /dev/null 2> /dev/null
fi

exit 0
