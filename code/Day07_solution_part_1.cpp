#include <algorithm>
#include <array>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>

namespace{

constexpr std::string_view Input =

false ?

"32T3K 765\n"
"T55J5 684\n"
"KK677 28\n"
"KTJJT 220\n"
"QQQJA 483\n"

:

"QAAQT 665\n"
"5K355 312\n"
"Q5T46 440\n"
"A3AJA 461\n"
"QQ9KQ 825\n"
"QJJQQ 51\n"
"7J7A5 37\n"
"8J887 774\n"
"AK3K4 62\n"
"A399A 110\n"
"75845 946\n"
"KAAAA 226\n"
"J9976 869\n"
"627Q8 917\n"
"K2252 216\n"
"A44AA 867\n"
"2TT39 160\n"
"65566 225\n"
"K6KK6 655\n"
"42T34 787\n"
"T6636 347\n"
"QTQTT 371\n"
"83T33 878\n"
"Q9928 742\n"
"JQ85Q 423\n"
"JQJQ2 654\n"
"63TA5 645\n"
"TQ8JQ 884\n"
"T44T4 6\n"
"5J523 83\n"
"87Q42 527\n"
"3J7A7 530\n"
"K99KT 158\n"
"326A7 546\n"
"T2AQ2 8\n"
"99JAA 464\n"
"QQQ9T 988\n"
"J6466 568\n"
"4Q9Q5 182\n"
"J89TJ 63\n"
"66J55 870\n"
"Q35QQ 1\n"
"2K637 46\n"
"T76T8 280\n"
"9A9QA 634\n"
"Q6AAA 486\n"
"88986 350\n"
"4J266 875\n"
"JJ666 116\n"
"38338 422\n"
"A72KQ 799\n"
"A26Q7 666\n"
"33434 788\n"
"32845 457\n"
"9A36A 995\n"
"328Q2 77\n"
"KQ688 238\n"
"5885T 455\n"
"52822 145\n"
"32555 125\n"
"85557 574\n"
"34422 790\n"
"KJ777 428\n"
"JJ777 122\n"
"26852 914\n"
"TKAQ5 819\n"
"374QK 918\n"
"Q365T 462\n"
"62359 179\n"
"J22QJ 367\n"
"55655 641\n"
"JTK4J 679\n"
"K3KK5 711\n"
"A2353 688\n"
"5556J 40\n"
"QQQ79 167\n"
"8K38K 676\n"
"KJJ6J 61\n"
"AA5JA 544\n"
"KKK7K 375\n"
"3Q7QQ 775\n"
"22K88 71\n"
"55KKJ 101\n"
"5J55J 982\n"
"AJTTT 541\n"
"T84KT 343\n"
"T77TA 162\n"
"AT296 31\n"
"T7AJ7 334\n"
"K3K44 310\n"
"TT49A 281\n"
"27648 18\n"
"34449 156\n"
"49489 763\n"
"42924 672\n"
"85886 118\n"
"J6793 800\n"
"5878K 659\n"
"8J26J 21\n"
"384Q3 822\n"
"AAJJJ 949\n"
"77262 643\n"
"66545 411\n"
"24J8Q 520\n"
"TTTT9 314\n"
"7JA7A 473\n"
"2QQJQ 335\n"
"J88KK 721\n"
"32223 251\n"
"J222Q 403\n"
"8J8AA 277\n"
"39QJ6 187\n"
"3Q99J 830\n"
"Q8TT5 240\n"
"J22KK 519\n"
"4J4JQ 928\n"
"7774J 239\n"
"85535 415\n"
"Q38Q9 171\n"
"T8833 588\n"
"3367A 781\n"
"62224 100\n"
"3J8T8 210\n"
"48J88 834\n"
"6Q66Q 301\n"
"3A6K6 586\n"
"2A3K2 419\n"
"83T62 712\n"
"7JJ49 82\n"
"JQ798 66\n"
"97947 921\n"
"A478A 223\n"
"25QA7 602\n"
"3KJ96 729\n"
"KK33K 543\n"
"44Q74 386\n"
"5A635 753\n"
"K33AK 400\n"
"QJ666 756\n"
"QAK7K 564\n"
"J8AKA 682\n"
"28A6T 887\n"
"8AAT7 191\n"
"T6587 612\n"
"JJJ22 430\n"
"55A5A 303\n"
"TT388 976\n"
"33A33 388\n"
"KKAJA 933\n"
"KK852 922\n"
"QTTTT 333\n"
"4T5J4 509\n"
"T99TT 394\n"
"977TJ 785\n"
"88222 862\n"
"442J2 719\n"
"74234 138\n"
"J5KJ8 909\n"
"J6JAA 341\n"
"TQQ4J 381\n"
"55585 111\n"
"T7Q7J 396\n"
"53T65 562\n"
"9K7KK 220\n"
"57J79 356\n"
"KA74Q 687\n"
"JQ687 662\n"
"62A5K 326\n"
"9TTQ9 163\n"
"59595 49\n"
"JKJKK 727\n"
"37369 539\n"
"JAJAA 68\n"
"9KQ43 477\n"
"46J4J 945\n"
"39333 701\n"
"38J65 767\n"
"K93JA 941\n"
"75725 529\n"
"97K9K 615\n"
"26AAK 579\n"
"6A565 420\n"
"5T555 650\n"
"AA788 87\n"
"K2799 969\n"
"TTJQT 185\n"
"K88KK 515\n"
"37Q87 495\n"
"T65QQ 275\n"
"4QQ53 638\n"
"68662 758\n"
"42288 731\n"
"36Q66 789\n"
"JAAA8 924\n"
"J2K77 443\n"
"82Q82 569\n"
"66T6A 476\n"
"TTKTK 108\n"
"74444 993\n"
"J5555 658\n"
"T89J9 38\n"
"23332 246\n"
"K4982 279\n"
"KK4KT 501\n"
"44454 233\n"
"QT398 866\n"
"4447T 432\n"
"4T944 939\n"
"2T828 549\n"
"266TT 72\n"
"99929 814\n"
"49632 256\n"
"4499J 124\n"
"Q5QJ4 573\n"
"48664 175\n"
"76A8J 795\n"
"Q82TJ 245\n"
"JQ39K 336\n"
"57297 689\n"
"33KJJ 959\n"
"64T4T 534\n"
"63636 809\n"
"688T8 583\n"
"84J34 35\n"
"4TJQJ 94\n"
"399QQ 479\n"
"99996 577\n"
"76633 13\n"
"A3AK8 298\n"
"AAA22 697\n"
"88J8T 19\n"
"44Q3Q 610\n"
"99J99 315\n"
"88843 636\n"
"2AAAJ 953\n"
"53535 603\n"
"47AK6 811\n"
"AA65A 642\n"
"K2QA9 902\n"
"34K8A 748\n"
"JA738 611\n"
"7A777 829\n"
"Q6Q77 559\n"
"QQJQQ 991\n"
"23222 368\n"
"755A5 536\n"
"7A987 177\n"
"Q47K8 624\n"
"69666 705\n"
"KK233 329\n"
"J9J44 450\n"
"J22J2 670\n"
"A55JA 926\n"
"229K2 827\n"
"T8A36 237\n"
"22526 490\n"
"KKK5K 75\n"
"9729J 693\n"
"9K829 609\n"
"T293Q 796\n"
"J8A44 931\n"
"K9J46 441\n"
"75776 149\n"
"6KJK2 675\n"
"TT7QT 507\n"
"27K2J 533\n"
"72444 764\n"
"4QA89 990\n"
"A5238 754\n"
"K5335 152\n"
"2K372 132\n"
"37J73 328\n"
"A7TQ9 965\n"
"2T22T 484\n"
"66T4T 199\n"
"3K333 337\n"
"9854K 20\n"
"TAAQ2 103\n"
"A44T6 81\n"
"7262J 510\n"
"K92AJ 983\n"
"827A5 614\n"
"23773 980\n"
"9Q524 166\n"
"333JJ 463\n"
"AA4JQ 911\n"
"QQ282 313\n"
"9K75A 873\n"
"9Q484 332\n"
"Q7J77 114\n"
"TATKA 218\n"
"2TTTT 798\n"
"3Q335 966\n"
"33QJQ 212\n"
"4Q55A 901\n"
"947A9 736\n"
"92J48 465\n"
"4TTKJ 50\n"
"8J898 604\n"
"2TJ52 840\n"
"Q9JJ8 813\n"
"7KQQ4 958\n"
"55453 282\n"
"4AAAJ 183\n"
"5998J 65\n"
"597JJ 480\n"
"QQQQ3 207\n"
"Q78KJ 720\n"
"J9993 331\n"
"K7J57 677\n"
"J8868 597\n"
"36238 770\n"
"48K28 517\n"
"K57T7 43\n"
"7K737 305\n"
"22J22 553\n"
"32J22 691\n"
"A3K86 259\n"
"J6A6Q 135\n"
"5QAQA 164\n"
"A2J2A 595\n"
"9K3Q3 557\n"
"J3J9J 552\n"
"83222 703\n"
"9Q9JQ 113\n"
"T676J 823\n"
"K4446 85\n"
"TQJK6 250\n"
"T6KTQ 376\n"
"6AKT5 294\n"
"7AA22 243\n"
"26QJQ 398\n"
"K4T28 141\n"
"T58KA 73\n"
"J5Q4K 47\n"
"AAA59 652\n"
"QA4K9 622\n"
"T888T 967\n"
"7375J 726\n"
"AKA5A 14\n"
"A3A5Q 894\n"
"88588 7\n"
"94664 354\n"
"T9926 29\n"
"54JJJ 776\n"
"AQ3K9 752\n"
"J8TT8 105\n"
"65TA8 421\n"
"99966 269\n"
"92JKT 296\n"
"KKKK4 673\n"
"2JQ2T 832\n"
"KAKK9 262\n"
"992J3 554\n"
"66868 700\n"
"AA2AA 351\n"
"Q4743 851\n"
"34394 355\n"
"T6T69 732\n"
"TA549 155\n"
"QQ99Q 300\n"
"33QKJ 555\n"
"A4444 833\n"
"3KJK3 563\n"
"65A78 831\n"
"KAKK8 744\n"
"5QQKQ 985\n"
"5754J 769\n"
"666JA 414\n"
"TKKKK 23\n"
"93K5J 837\n"
"85558 78\n"
"K6286 663\n"
"T8K58 735\n"
"56JAA 224\n"
"4T94T 345\n"
"63333 172\n"
"58356 853\n"
"666TK 30\n"
"A77AQ 896\n"
"68QA8 174\n"
"924KA 292\n"
"92TJ2 898\n"
"J5859 230\n"
"QTTT6 319\n"
"AAJAA 860\n"
"28A4Q 714\n"
"K274T 671\n"
"73337 28\n"
"979JT 899\n"
"8KKKK 740\n"
"4Q99Q 944\n"
"KKKJ7 718\n"
"Q7JQQ 438\n"
"73K3T 999\n"
"5J25J 379\n"
"5999A 416\n"
"T9922 265\n"
"7K485 648\n"
"3A57K 686\n"
"777J8 695\n"
"KT999 274\n"
"2554Q 500\n"
"T2226 284\n"
"Q8QQQ 302\n"
"KJK9K 556\n"
"53A99 52\n"
"768K3 488\n"
"55JA5 115\n"
"K3K77 986\n"
"77KJK 804\n"
"86585 390\n"
"39699 469\n"
"TTT53 859\n"
"26266 628\n"
"87858 200\n"
"J9Q7K 359\n"
"J8AQ4 377\n"
"3998Q 76\n"
"99994 161\n"
"3587J 728\n"
"K9K33 816\n"
"J8Q8J 456\n"
"894J9 733\n"
"T4J65 514\n"
"72767 613\n"
"5T8K2 370\n"
"KAKA6 855\n"
"A3QJ3 738\n"
"JQ537 504\n"
"83323 271\n"
"KK667 558\n"
"QKQ8Q 908\n"
"4TAAA 34\n"
"35Q95 625\n"
"T9777 323\n"
"66664 9\n"
"99A66 631\n"
"888JA 244\n"
"J745Q 635\n"
"ATJ4T 107\n"
"49KQ7 757\n"
"95999 242\n"
"4A422 560\n"
"6QJ2A 854\n"
"77288 646\n"
"6TTJ6 989\n"
"T777T 524\n"
"34A34 22\n"
"3A362 295\n"
"66967 528\n"
"J77K3 297\n"
"22T7K 485\n"
"33J34 904\n"
"83J38 287\n"
"98KA2 372\n"
"74Q6A 221\n"
"KKK55 348\n"
"QQ222 838\n"
"7TTQ5 342\n"
"KKK9K 640\n"
"22922 405\n"
"QQQTQ 633\n"
"98T87 912\n"
"55357 449\n"
"92333 198\n"
"76777 470\n"
"48JTK 849\n"
"J9779 321\n"
"95557 64\n"
"J9299 605\n"
"2JQK2 578\n"
"36634 44\n"
"TTKKJ 90\n"
"T4666 190\n"
"TA7K4 364\n"
"8T85A 330\n"
"J92J2 717\n"
"22945 606\n"
"756K6 561\n"
"8632K 452\n"
"747KK 365\n"
"T68J6 195\n"
"JA454 587\n"
"QK849 793\n"
"594J8 812\n"
"92559 970\n"
"89829 130\n"
"Q6849 571\n"
"4TA4T 996\n"
"TQ24Q 846\n"
"T8T3T 792\n"
"AA5A7 338\n"
"553A8 325\n"
"KK95J 566\n"
"Q4443 734\n"
"T923K 512\n"
"939Q9 716\n"
"K3TJ3 864\n"
"5T9J2 590\n"
"22522 644\n"
"88444 778\n"
"97779 475\n"
"5AJK5 548\n"
"344A4 618\n"
"TT252 508\n"
"6T359 466\n"
"2AA2Q 446\n"
"TAATA 916\n"
"6K6KJ 954\n"
"4AAK5 255\n"
"T433T 952\n"
"299K6 389\n"
"33343 399\n"
"QJAAA 98\n"
"JQ3Q9 601\n"
"39999 521\n"
"8A3J3 847\n"
"99339 791\n"
"JTJTT 661\n"
"9AKQT 451\n"
"5Q5K5 651\n"
"42242 955\n"
"Q2266 794\n"
"5JJK7 227\n"
"QQKJ6 454\n"
"TJ9T9 15\n"
"K4K46 254\n"
"Q9KKK 213\n"
"Q8844 786\n"
"8922K 998\n"
"J877J 617\n"
"77929 412\n"
"J8A66 531\n"
"555TT 513\n"
"K6Q49 268\n"
"64464 801\n"
"99JJ9 523\n"
"626A7 709\n"
"7AQQQ 835\n"
"66AA6 938\n"
"88T56 667\n"
"KKKJ4 960\n"
"48999 503\n"
"4494J 496\n"
"K883J 391\n"
"2KK99 119\n"
"7737A 270\n"
"KQJ69 550\n"
"33KA8 723\n"
"T3JT9 893\n"
"99899 444\n"
"T847J 134\n"
"J9694 616\n"
"55AAQ 1000\n"
"3742T 660\n"
"44QK4 940\n"
"7777K 773\n"
"TTT5T 923\n"
"JKJKJ 150\n"
"9KK99 649\n"
"AJ546 2\n"
"A999A 694\n"
"KA4A6 828\n"
"9AJA4 168\n"
"555Q5 353\n"
"64J46 426\n"
"55KTA 327\n"
"86688 747\n"
"J8883 905\n"
"2JQ2Q 460\n"
"59826 120\n"
"T843K 600\n"
"52252 32\n"
"Q62J9 576\n"
"38777 684\n"
"3T433 418\n"
"4J4AA 772\n"
"QQKJJ 621\n"
"A9637 815\n"
"99JK3 74\n"
"35J99 349\n"
"98334 402\n"
"86K42 215\n"
"T8J3A 930\n"
"89A38 627\n"
"8JJ87 730\n"
"T6256 664\n"
"68445 264\n"
"47673 858\n"
"AT28A 803\n"
"8KQ28 392\n"
"33JK3 425\n"
"53999 11\n"
"68TJ8 59\n"
"7K7K7 241\n"
"64379 383\n"
"K3TQ4 581\n"
"T5Q88 593\n"
"77474 60\n"
"887JA 252\n"
"44446 852\n"
"J9393 971\n"
"8A633 492\n"
"74479 589\n"
"2Q555 565\n"
"8J888 407\n"
"97Q5A 178\n"
"48632 16\n"
"4K6QT 805\n"
"3Q333 106\n"
"T36J3 17\n"
"AAKKK 981\n"
"AAJQQ 194\n"
"9Q393 584\n"
"JTKK9 505\n"
"J986K 3\n"
"55KJ5 285\n"
"8K882 920\n"
"8KA82 232\n"
"9AAA9 656\n"
"22J92 630\n"
"QQQQA 522\n"
"7A652 25\n"
"T4665 591\n"
"T7TAT 447\n"
"87KK7 762\n"
"QT967 493\n"
"Q3QJ6 580\n"
"A8T6T 180\n"
"88J58 843\n"
"KKKTQ 957\n"
"45K2K 380\n"
"22343 749\n"
"K8T88 963\n"
"3T4QJ 48\n"
"T59AQ 136\n"
"QKKQJ 487\n"
"353J5 283\n"
"4J8Q5 936\n"
"7747A 844\n"
"52562 992\n"
"6JJ64 888\n"
"8Q33J 102\n"
"K86A4 373\n"
"747A9 572\n"
"JA22Q 184\n"
"79333 236\n"
"9Q65K 532\n"
"4J677 234\n"
"A2J74 154\n"
"92339 4\n"
"J3337 751\n"
"67A5T 248\n"
"A8AAA 339\n"
"37K3K 413\n"
"43337 678\n"
"93QQ3 69\n"
"5KQJK 346\n"
"T9T99 324\n"
"66T66 802\n"
"3T792 79\n"
"57575 231\n"
"J47JT 715\n"
"62666 657\n"
"997K9 128\n"
"32TK7 253\n"
"96294 877\n"
"63666 5\n"
"KK397 408\n"
"4A4J4 97\n"
"Q4265 146\n"
"AKJAA 948\n"
"J5Q94 263\n"
"ATTTT 575\n"
"4827T 133\n"
"47AK9 683\n"
"68T47 567\n"
"2QK28 445\n"
"T22JT 607\n"
"662QQ 181\n"
"QQ6QQ 153\n"
"92292 582\n"
"96K9J 173\n"
"2J299 404\n"
"T333T 273\n"
"25J55 362\n"
"6AJ2T 929\n"
"5K323 710\n"
"9944K 453\n"
"A9Q49 755\n"
"TTQ5T 962\n"
"444Q4 311\n"
"76666 176\n"
"9946K 690\n"
"KK3QJ 471\n"
"ATTT6 247\n"
"2A2K8 112\n"
"A4T9Q 692\n"
"777J7 839\n"
"595J4 206\n"
"TAATT 629\n"
"53333 883\n"
"A59T6 707\n"
"44525 906\n"
"Q8J8Q 137\n"
"T3J93 696\n"
"47464 340\n"
"J2822 907\n"
"JJ559 196\n"
"55343 653\n"
"9K9Q9 674\n"
"8TQQQ 211\n"
"7J275 70\n"
"22Q5J 276\n"
"66564 129\n"
"TJTJJ 489\n"
"KK6KK 409\n"
"5Q98A 157\n"
"78777 857\n"
"67667 807\n"
"5QK98 39\n"
"K35J6 592\n"
"96KT2 109\n"
"4KK44 127\n"
"T6253 768\n"
"85989 836\n"
"55445 299\n"
"T9736 121\n"
"A696A 950\n"
"T48QT 668\n"
"644K6 518\n"
"JJJJJ 876\n"
"TQ6AT 759\n"
"KK83K 260\n"
"73777 214\n"
"6K66Q 598\n"
"5K39A 169\n"
"64T7T 219\n"
"238J2 442\n"
"4J22Q 203\n"
"Q9TA6 291\n"
"5T86J 26\n"
"T439K 272\n"
"44244 817\n"
"K8844 459\n"
"K5KK7 975\n"
"A666Q 842\n"
"8T6Q7 434\n"
"63Q4J 42\n"
"966J9 637\n"
"JA6KA 863\n"
"A5555 972\n"
"T2222 745\n"
"AAA7A 499\n"
"Q359T 436\n"
"A2A5A 879\n"
"QQQQ5 623\n"
"K4T5T 724\n"
"A888A 987\n"
"5J535 201\n"
"5A9K6 123\n"
"4QJ43 431\n"
"75J4J 491\n"
"283J8 698\n"
"T7T8T 448\n"
"33J76 197\n"
"47QJA 24\n"
"2T272 951\n"
"A7A87 142\n"
"J3TT3 540\n"
"4JJ44 961\n"
"KJJ63 478\n"
"92QQ9 278\n"
"TJTTT 192\n"
"TJK68 307\n"
"37773 290\n"
"QQQT6 126\n"
"QJQ9Q 401\n"
"24K3A 186\n"
"8443Q 820\n"
"33592 56\n"
"87923 497\n"
"TTJ8Q 632\n"
"J4544 934\n"
"6K666 474\n"
"68566 739\n"
"A4AAA 669\n"
"89899 139\n"
"842K3 596\n"
"K5AA5 429\n"
"85885 599\n"
"59779 437\n"
"A336J 779\n"
"TT3A3 366\n"
"97Q7A 261\n"
"83393 545\n"
"Q6Q6T 974\n"
"37T2J 890\n"
"38333 58\n"
"28227 363\n"
"TTT66 33\n"
"32333 468\n"
"A8T55 824\n"
"88889 435\n"
"KQQ3Q 385\n"
"T6685 318\n"
"5K76J 202\n"
"75777 99\n"
"53566 55\n"
"TTKJT 481\n"
"875J9 551\n"
"447A7 947\n"
"T2TT7 147\n"
"T2726 810\n"
"TT6TT 856\n"
"QK9JQ 27\n"
"A786Q 897\n"
"44J44 542\n"
"98QJ3 189\n"
"J4448 89\n"
"Q8Q8Q 417\n"
"59473 57\n"
"99K99 148\n"
"662AJ 361\n"
"7TTTT 994\n"
"26T97 36\n"
"7A69T 746\n"
"95JA5 516\n"
"J9J8K 886\n"
"57333 358\n"
"4TJQA 881\n"
"T5628 151\n"
"72A59 205\n"
"QK777 249\n"
"84649 397\n"
"T7T96 761\n"
"4TAQQ 378\n"
"24274 494\n"
"KJ3KK 845\n"
"TT77T 384\n"
"8J88J 722\n"
"A25T4 880\n"
"88868 861\n"
"Q5QK2 502\n"
"35344 267\n"
"K99AA 777\n"
"2T375 903\n"
"4484Q 891\n"
"J8AQA 67\n"
"QJ578 935\n"
"T72T7 482\n"
"5AQK8 973\n"
"T3AA9 848\n"
"8TJJ7 165\n"
"88J75 322\n"
"T8T8A 54\n"
"93524 956\n"
"29T9Q 458\n"
"66272 647\n"
"TQTQQ 681\n"
"629J4 483\n"
"6676T 708\n"
"9QT99 704\n"
"67977 942\n"
"737J7 808\n"
"T785K 865\n"
"7AAA4 943\n"
"88Q8J 619\n"
"QK663 91\n"
"9734J 818\n"
"J4TTT 895\n"
"5A585 80\n"
"8JJJJ 159\n"
"7T298 170\n"
"8998A 140\n"
"TT5T2 266\n"
"44443 53\n"
"57565 439\n"
"T579A 317\n"
"A5QAA 235\n"
"A665A 84\n"
"223J3 766\n"
"T63AJ 741\n"
"62K97 760\n"
"Q8Q33 538\n"
"A5955 293\n"
"JKKKK 86\n"
"88228 10\n"
"376J7 93\n"
"7343T 535\n"
"KQK44 882\n"
"KKK76 395\n"
"9229K 526\n"
"J63J8 320\n"
"ATKKK 104\n"
"T4JT4 850\n"
"79A9A 780\n"
"AA6A3 387\n"
"6A542 889\n"
"45242 228\n"
"KJ75Q 369\n"
"52T29 41\n"
"A9924 309\n"
"A7838 925\n"
"2738J 229\n"
"22262 782\n"
"A55AA 144\n"
"77727 88\n"
"86556 188\n"
"46443 997\n"
"666J6 900\n"
"99968 12\n"
"9AA49 927\n"
"68666 467\n"
"52K68 750\n"
"3J339 498\n"
"43634 304\n"
"TJK46 585\n"
"43533 511\n"
"55245 537\n"
"39K3J 765\n"
"65J54 937\n"
"5T684 594\n"
"22Q74 868\n"
"25255 871\n"
"5TTJ5 797\n"
"93J7A 784\n"
"AAAQ8 357\n"
"7J727 968\n"
"44T44 821\n"
"77533 608\n"
"KQQ83 547\n"
"72222 680\n"
"44A4A 406\n"
"8932K 222\n"
"KK59K 874\n"
"774K4 92\n"
"29992 570\n"
"3333J 620\n"
"39393 506\n"
"74773 892\n"
"T79Q8 208\n"
"TTT3T 885\n"
"QQQ8A 374\n"
"99979 360\n"
"2965T 872\n"
"AA6AJ 96\n"
"383K9 826\n"
"7TK7K 685\n"
"6J755 979\n"
"2QQQ2 706\n"
"TTT4T 525\n"
"3K767 699\n"
"75J8J 639\n"
"KTJK3 743\n"
"7972T 308\n"
"77573 143\n"
"J253K 286\n"
"TQK85 316\n"
"6235A 193\n"
"338TT 393\n"
"JT8T5 352\n"
"JA4JA 984\n"
"JAQ86 737\n"
"9T589 306\n"
"KJQQQ 424\n"
"JJKTK 964\n"
"QTJTQ 783\n"
"6J626 289\n"
"24Q22 131\n"
"QAT5A 919\n"
"6486K 702\n"
"QT464 288\n"
"A6972 841\n"
"Q99Q9 977\n"
"4JJ43 209\n"
"66AA8 910\n"
"Q34QT 806\n"
"Q8J4Q 472\n"
"979TT 932\n"
"A8A8A 204\n"
"9A34Q 382\n"
"QT89A 713\n"
"JQJJQ 427\n"
"8338K 978\n"
"99T99 913\n"
"6A444 257\n"
"4K5KK 45\n"
"55K55 217\n"
"K8866 915\n"
"42577 771\n"
"45564 725\n"
"Q2TAQ 433\n"
"Q9AA6 258\n"
"867A3 117\n"
"A9799 95\n"
"74778 344\n"
"A2727 410\n"
"78888 626\n"
;

enum class HandType { NoneYet = 0, Different, Pair, DouplePair, Three, Full, Four, Five };

constexpr auto HandSize = 5U;
using HandCards = std::array<char, HandSize>;
using Hand = std::pair<HandCards, HandType>;

constexpr auto CardsToStr
    = [](const HandCards& fc) { return std::string_view(fc.data(), HandSize); };
constexpr auto TypeToStr = [](const HandType ht) {
    switch (ht) {
    case HandType::NoneYet:
        return "NONE!";
    case HandType::Different:
        return "Different";
    case HandType::Pair:
        return "Pair";
    case HandType::DouplePair:
        return "DouplePair";
    case HandType::Three:
        return "Three";
    case HandType::Full:
        return "Full";
    case HandType::Four:
        return "Four";
    case HandType::Five:
        return "Five";
    default:
        throw std::runtime_error("Unknown hand type");
    }
};

bool toUnsigned(const std::string& s, unsigned long& res) {
    try {
        if (s.empty()) {
            return false;
        }
        if (!std::all_of(std::next(s.cbegin()), s.cend(), [](const char ch) {
                return std::isdigit(ch); // avoid first, with '-' in order to allow '-0'.
            })) {
            // stoul would ignore tailing non-digits.
            // Here ignore first char, that is, allowing '-' (specific check later for future use).
            return false;
        }
        res = std::stoul(s);
        // Note also that stoul would have converted into unsigned a value starting with minus
        // ('-').

        if (s.find('-') != std::string::npos) {
            // stoul converts negative values with a reinterpret cast.
            if (s.substr(0U, 2U) != "-0") {
                return false;
            }
        }

        return errno != ERANGE;
    } catch (...) {
        // std::invalid_argument, eventually std::out_of_range
        return false;
    }
}

} // namespace

auto day07Part1(std::string_view streamSource, bool sourceIsFilePath)
{
    std::shared_ptr<std::istream> inputStream;

    if (sourceIsFilePath) {
        inputStream = std::static_pointer_cast<std::istream>(
            std::make_shared<std::ifstream>(std::string(streamSource)));
    } else {
        auto sstream = std::make_shared<std::stringstream>();
        (*sstream) << streamSource;
        // use std::move(sstream) in C++20 or more.
        inputStream = std::static_pointer_cast<std::istream>(sstream);
    }


    constexpr auto ZeroForUnknownCard = 0U;
    const auto computeCard = [](const char card) {
        if (std::isdigit(card)) {
            return static_cast<unsigned>(card - '0');
        }

        constexpr auto Ten = 10U;
        constexpr auto Jack = 11U;
        constexpr auto Queen = 12U;
        constexpr auto King = 13U;
        constexpr auto Ace = 14U;

        switch (card) {
        case 'T':
            return Ten;
        case 'J':
            return Jack;
        case 'Q':
            return Queen;
        case 'K':
            return King;
        case 'A':
            return Ace;
        default:
            return ZeroForUnknownCard;
        }
    };

    const auto computeHand = [](const HandCards& cards) {
        std::map<char, unsigned> cardsNumber;

        HandType t = HandType::Different; // eventually to change

        for (size_t i = 0; i < HandSize; ++i) {
            constexpr auto Five = 5U;
            switch (++(cardsNumber[cards.at(i)])) {
            case Five:
                t = HandType::Five;
                return t; // ended cards.
            case 4U:
                t = HandType::Four;
                break;
                // not return, Five still possible
            case 3U:
                t = HandType::Three;
                for (auto [c, n] : cardsNumber) {
                    if (n == 2U) {
                        t = HandType::Full;
                        return t; // ended cards.
                    }
                }
                // not return, something more still possible
                break;
            case 2U:
                t = HandType::Pair;
                // std::cout << "Evaluated Pair maybe" << std::endl;
                for (auto [c, n] : cardsNumber) {
                    if (c == cards.at(i)) {
                        continue;
                    }
                    if (n == 3U) {
                        t = HandType::Full;
                        return t; // ended cards.
                    }
                    if (n == 2U) {
                        t = HandType::DouplePair;
                        // not return, Full still possible
                    }
                }
                break;
            default:
                break;
            }
        }

        return t;
    };

    const auto handCompare = [&computeCard](const Hand& h1, const Hand& h2) {
        if (h1.second < h2.second) {
            return true;
        }
        if (h1.second > h2.second) {
            return false;
        }

        if (h1.second == h2.second) {
            const auto& cards1 = h1.first;
            const auto& cards2 = h2.first;
            for (size_t i = 0U; i < HandSize; ++i) {
                const auto c1 = computeCard(cards1.at(i));
                const auto c2 = computeCard(cards2.at(i));

                if (c1 < c2) {
                    return true;
                }
                if (c1 > c2) {
                    return false;
                }
            }
        }

        return false;
    };

    std::map<Hand, unsigned long, decltype(handCompare)> hands(handCompare);

    unsigned lineCount{0U};

    constexpr auto MaxLineLength = 1000;
    std::array<char, MaxLineLength + 1> cc{};
    while (inputStream->getline(cc.data(), MaxLineLength, '\n')) {
        ++lineCount;
        std::string errorLine = "Input error at the line n. "
            + std::to_string(static_cast<int>(lineCount)) + " : ";

        auto c = static_cast<size_t>(inputStream->gcount());
        // 'c' includes the delimiter, which is replaced by '\0'.
        if (c > MaxLineLength) {
            throw std::invalid_argument(
                errorLine + "longer than " + std::to_string(MaxLineLength));
        }

        std::string line;
        // std::cout << "length = " << c << '\n';
        if (cc.at(c - 1U) == '\0') { // 'c' is positive as line has been extracted.
            --c; // excludes '\0' that replaced the delimiter '\n'.
        }
        line = std::string_view(cc.data(), c);
        // std::cout << "line: " << line << '\n';

        std::stringstream lineStream;
        lineStream << line;

        std::string tokenHand;
        std::string tokenRank;

        if (!(lineStream >> tokenHand)) {
            throw std::invalid_argument(errorLine + "no hand!");
        }
        HandCards cards;
        if (tokenHand.length() != HandSize) {
            throw std::invalid_argument(
                // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                errorLine + "unexpected card sequence length: " + tokenHand);
        }
        for (size_t i = 0U; i < HandSize; ++i) {
            const auto card = tokenHand[i];
            if (computeCard(card) == ZeroForUnknownCard) {
                // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                throw std::invalid_argument(errorLine + "bad hand card: " + card);
            }
            cards.at(i) = card;
        }

        if (!(lineStream >> tokenRank)) {
            throw std::invalid_argument(errorLine + "no rank!");
        }
        unsigned long rank{};
        if (!toUnsigned(tokenRank, rank)) {
            // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
            throw std::invalid_argument(errorLine + "not a rank number: " + tokenRank);
        }

        Hand h = std::make_pair(cards, computeHand(cards));

        if (hands.count(h)) {
            throw std::invalid_argument(
                // NOLINTNEXTLINE(performance-inefficient-string-concatenation)
                errorLine + "repeated hand, the code has to be generalized: " + tokenHand);
        }
        hands[h] = rank;

        // std::cout << "Hand " << tokenHand << std::endl;
        // std::cout << "Hands n. " << hands.size() << std::endl;

        if (!lineStream.eof()) {
            throw std::invalid_argument(errorLine + "more than two tokens");
        }
    }

    size_t i = 0U;
    unsigned long res = std::accumulate(
        hands.begin(), hands.end(), 0UL, [&i](unsigned long acc, const auto& hr) {
            ++i;
            // std::cout << "Hand n. " << i << " = " << CardsToStr(hr.first.first) << " Type "
            //           << TypeToStr(hr.first.second) << std::endl;
            return acc + (hr.second * i);
        });

    std::cout << "\nResult: " << res << std::endl;

    return res;
}

int main()
{
    try {
        day07Part1(Input, false);
        // day07Part1("./07_input_file.txt",true);
    } catch (std::invalid_argument& ex) {
        std::cerr << "Bad input: " << ex.what() << std::endl;
        return 1;
    } catch (std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error: " << std::endl;
        return 1;
    }

    return 0;
}


/*
OUTPUT:

Example:
Hand n. 1 = 32T3K Type Pair
Hand n. 2 = KTJJT Type DouplePair
Hand n. 3 = KK677 Type DouplePair
Hand n. 4 = T55J5 Type Three
Hand n. 5 = QQQJA Type Three
Result: 6440

Real input:
Hand n. 1 = 24J8Q Type Different
Hand n. 2 = 24K3A Type Different
Hand n. 3 = 25QA7 Type Different
Hand n. 4 = 26T97 Type Different
Hand n. 5 = 2738J Type Different
Hand n. 6 = 27648 Type Different
Hand n. 7 = 28A4Q Type Different
Hand n. 8 = 28A6T Type Different
Hand n. 9 = 2965T Type Different
Hand n. 10 = 2T375 Type Different
...
Hand n. 990 = KKKK4 Type Four
Hand n. 991 = KAAAA Type Four
Hand n. 992 = A4444 Type Four
Hand n. 993 = A4AAA Type Four
Hand n. 994 = A5555 Type Four
Hand n. 995 = A8AAA Type Four
Hand n. 996 = ATTTT Type Four
Hand n. 997 = AA2AA Type Four
Hand n. 998 = AAJAA Type Four
Hand n. 999 = AAA7A Type Four
Hand n. 1000 = JJJJJ Type Five
Result: 251806792
*/
