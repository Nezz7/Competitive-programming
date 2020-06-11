#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e8 + 9;
LL M = 1LL << 40;
LL s0 = 1611516670;
int block = 1e6;
LL start = 350125310;
LL all_start = 175147925;
LL periode = 182129209;
LL all_periode = 266177229 - all_start;
LL before[] = {502983, 492323, 502952, 500586, 501556, 500993, 498796, 498892, 501739, 503544, 508333, 498738, 499566, 501599, 487429, 502826, 496833, 500775, 503597, 501956, 498154, 501371, 500216, 497493, 503079, 499800, 500632, 496952, 504980, 502990, 503165, 500387, 500831, 497738, 503639, 500330, 498970, 500501, 497853, 497310, 501318, 501068, 506576, 507123, 501941, 501037, 506080, 494812, 498246, 500688, 502099, 501139, 505857, 498113, 500691, 500785, 501850, 498368, 499512, 500521, 499741, 497699, 501769, 498255, 500785, 502439, 502099, 499875, 501778, 497931, 502305, 493863, 500435, 501873, 500371, 495259, 501197, 501666, 499806, 503451, 504429, 496208, 502418, 501694, 498656, 503388, 501442, 501845, 501651, 502400, 497713, 498239, 499153, 498454, 497697, 498219, 497637, 504399, 501283, 507077, 500545, 500633, 499265, 501380, 507050, 498530, 500618, 496081, 495760, 499585, 500448, 497801, 500786, 504865, 499482, 501442, 499678, 499388, 503866, 493134, 501851, 501754, 497349, 498154, 497904, 499674, 506467, 497472, 502252, 502366, 499927, 504572, 506007, 501205, 500811, 502271, 499632, 497977, 503406, 498985, 495121, 499829, 499090, 498920, 501870, 501825, 502798, 499961, 498637, 499032, 503817, 502376, 500530, 501742, 503837, 496834, 504741, 500868, 498471, 501831, 500002, 497636, 498317, 497580, 494928, 498081, 498789, 499928, 504095, 497877, 501199, 500120, 497212, 496699, 498040, 496639, 498802, 495980, 496609, 502950, 498541, 497839, 497601, 504531, 497816, 496466, 505111, 507366, 502257, 499273, 500389, 501977, 508856, 503807, 499353, 501971, 500301, 505343, 498509, 501050, 498414, 493065, 500380, 496707, 500713, 506168, 496640, 497656, 499874, 501733, 495868, 499246, 503088, 497607, 502087, 508742, 504866, 496068, 502340, 491002, 502709, 500299, 498243, 499547, 497080, 496559, 504302, 499182, 498791, 493569, 497778, 500745, 501820, 505142, 507525, 502296, 501233, 501056, 503899, 498280, 498331, 500241, 501467, 504917, 507214, 502128, 498833, 494485, 503896, 497273, 499545, 498473, 503200, 495939, 501503, 499812, 499729, 501448, 506338, 498301, 503935, 493204, 497406, 505419, 502114, 498424, 508900, 498941, 501560, 500343, 496778, 496303, 497861, 499779, 499425, 499684, 507639, 501890, 497019, 499414, 506225, 498576, 501136, 501450, 495785, 492881, 508514, 499684, 499585, 504332, 494955, 502875, 499220, 499005, 501874, 501156, 501926, 500000, 499230, 500924, 501775, 500378, 497822, 493127, 501488, 502777, 499855, 501561, 499936, 498853, 497730, 500593, 498125, 494769, 499887, 502073, 496466, 502685, 499375, 497486, 497882, 500780, 504418, 497760, 498140, 500018, 500486, 503327, 500962, 497777, 498306, 498830, 498907, 500576, 500479, 499466, 499267, 495276, 503226, 499171, 499992, 498027, 502175, 497948, 499747, 492701, 497042, 496674, 498325, 500846, 62697, 0};
LL before_num[] = {1611516670, 24831098818, 85091177611, 241479741103, 647343511917, 6995323118, 38803296781, 121352198450, 335585309480, 891568792743, 14370630249, 57943890614, 171026377942, 464501064994, 1473880836, 24473902285, 84164171463, 239073950242, 641099940086, 6806229870, 38312556854, 120078616969, 332280076921, 882990965157, 14112718818, 57274551969, 169289292334, 459992934005, 1337854506, 24120883462, 83248007737, 236696297515, 634929391393, 6620357676, 37830176352, 118826730177, 329031146994, 874559255859, 13856007495, 56608327843, 167560289742, 455505780300, 1202088386, 23768539351, 82333594782, 234323188514, 628770636033, 6435063656, 37349296386, 117578737596, 325792323073, 866153773131, 13603643125, 55953385061, 165860564948, 451094609069, 1069184517, 23423623727, 81438460553, 232000112395, 622741727028, 6253085456, 36877021659, 116353077724, 322611458168, 857898708083, 13354228762, 55306098243, 164180708576, 446735001036, 937685173, 23082353134, 80552785887, 229701585730, 616776528825, 6072677726, 36408822720, 115137995242, 319458043535, 849714882133, 13107744445, 54666415645, 162520587621, 442426611046, 807311470, 22744003927, 79674693251, 227422736603, 610862399010, 5893434651, 35943646365, 113930757179, 316324986992, 841583890229, 12861712571, 54027907086, 160863512855, 438126126427, 677744489, 22407748132, 78802032994, 225157985322, 604984856037, 5716565771, 35484631509, 112739509636, 313233429815, 833560598601, 12619930630, 53400428095, 159235062884, 433899929956, 549348706, 22074532063, 77937262116, 222913708970, 599160450170, 5540033707, 35026490825, 111550530977, 310147760736, 825552588218, 12376359574, 52768306127, 157594563185, 429642460847, 421224956, 21742021880, 77074322838, 220674185952, 593348380684, 5364465484, 34570851523, 110368043254, 307078936923, 817588294774, 12137286578, 52147857402, 155984357764, 425463613204, 295498034, 21415731952, 76227526294, 218476557046, 587645035156, 5192879414, 34125546861, 109212377002, 304079721068, 809804649437, 11901289737, 51535392117, 154394871503, 421338536015, 170920662, 21092425584, 75388473090, 216299023615, 581993842114, 5021923689, 33681877906, 108060955255, 301091520582, 802049592223, 11668023988, 50930014590, 152823779731, 417261196672, 47523507, 20772181826, 74557367833, 214142117131, 576396181355, 4853507682, 33244800104, 106926639410, 298147713933, 794409746597, 11435650672, 50326953208, 151258698876, 413199457023, 1092995098244, 20453692433, 73730815694, 211997026857, 570829185964, 4685264556, 32808171177, 105793488505, 295206930517, 786777746632, 11206260411, 49731633517, 149713708985, 409189858068, 1082589280689, 20139991649, 72916691179, 209884189289, 565345893787, 4518737141, 32375994660, 104671892500, 292296134838, 779223572048, 10978265333, 49139934610, 148178116403, 405204647340, 1072246754882, 19827002537, 72104413141, 207776143636, 559875037177, 4354683110, 31950237454, 103566955958, 289428573982, 771781602051, 10752858133, 48554951837, 146659953560, 401264670349, 1062021621551, 19518274761, 71303194772, 205696800289, 554478669836, 4191483496, 31526697331, 102467773271, 286575945643, 764378384800, 10530470029, 47977804257, 145162124809, 397377465370, 1051933443521, 19213652728, 70512631458, 203645109528, 549154066966, 4030509852, 31108934194, 101383583168, 283762226666, 757076146220, 10309979851, 47405582216, 143677078963, 393523435027, 1041931361613, 18910272345, 69725290790, 201601781662, 543851168197, 3869893989, 30692099632, 100301802920, 280954761586, 749790137907, 10089997457, 46834678258, 142195453631, 389678281232, 1031952315675, 18609763453, 68945402068, 199577793939, 538598461112, 3711222251, 30280310451, 99233116795, 278181278692, 742592321221, 9872154607, 46269326711, 140728238241, 385870524711, 1022070324749, 18311382009, 68171034631, 197568134878, 533382940567, 3554026557, 29872351977, 98174372077, 275433596512, 735461463758, 9655697881, 45707572329, 139270358519, 382086996623, 1012251211594, 18014204912, 67399792486, 195566586555, 528188468873, 3397755113, 29466792348, 97121853126, 272702071066, 728372535169, 9442541797, 45154383935, 137834709208, 378361160925, 1002581823366, 17722589590, 66642984633, 193602498691, 523091215660, 3243839556, 29067346493, 96085200428, 270011722255, 721390470774, 9232083997, 44608198160, 136417233148, 374682489219, 993034836731, 17435952907, 65899097615, 191671943332, 518080986662, 3092594895, 28674832371, 95066537244, 267368060404, 714529568823, 9025028345, 44070841770, 135022671628, 371063286307, 983642184332, 17151396830, 65160610118, 189755401031, 513107125545, 2941349750, 28282316870, 94047870750, 264724390129, 707668644954, 8817435949, 43532092696, 133624495703, 367434702789, 974225187667, 0};
LL after[] = {494199, 496685, 497610, 499573, 500111, 499626, 500619, 502532, 499381, 498944, 493797, 502393, 501280, 498843, 494417, 498149, 500069, 500256, 498845, 506011, 500448, 500525, 502271, 501485, 495419, 497125, 503609, 501707, 500392, 498425, 503308, 502829, 500052, 499526, 496718, 498550, 499200, 498430, 503247, 501652, 498636, 501545, 505317, 492585, 499621, 499750, 500478, 497878, 498805, 497343, 500464, 497276, 507039, 501939, 499413, 499469, 487567, 497319, 499570, 500839, 499918, 503400, 501653, 500640, 501979, 498740, 500068, 496014, 500520, 497393, 497801, 502156, 501457, 498305, 501949, 490916, 500727, 499880, 499181, 499009, 502987, 503814, 499092, 499361, 505164, 503221, 495575, 498870, 500522, 495731, 500517, 501486, 501710, 497552, 498471, 502100, 501302, 498193, 500640, 504092, 497568, 505006, 502581, 501223, 498772, 501844, 498358, 498110, 488952, 499117, 501810, 501201, 506235, 504329, 502148, 501017, 502377, 499031, 499044, 503850, 499662, 497581, 508747, 500379, 496351, 498720, 503221, 503407, 494684, 501145, 505964, 503290, 495976, 496971, 502057, 500836, 494754, 499994, 499220, 499972, 504114, 499735, 499677, 499518, 500647, 500489, 490970, 501480, 497565, 497197, 502407, 496322, 499048, 501402, 502915, 500249, 503290, 496258, 500316, 495070, 496045, 502839, 498529, 503921, 499212, 500801, 499895, 501521, 501160, 498544, 499487, 499787, 498211, 499811, 495468, 496083, 499098, 497976, 500014, 499232, 498732, 501146, 64402, 0};
LL after_num[] = {516914, 20650189014, 74240768887, 213320471137, 574263823815, 4787889955, 33074507269, 106484690902, 297000757453, 791433134353, 11347508705, 50098204813, 150665044668, 411658789573, 1088996717416, 20333317063, 73418414371, 211186274752, 568725099726, 4621442711, 32642538921, 105363635318, 294091364163, 783882599030, 11118953800, 49505053095, 149125681925, 407663794807, 1078628800049, 20018803006, 72602179030, 209067959091, 563227591537, 4454720767, 32209857666, 104240729349, 291177168779, 776319601703, 10890588601, 48912393781, 147587596515, 403672114127, 1068269484544, 19706533656, 71791769459, 206964762495, 557769319218, 4290068946, 31782549017, 103131766532, 288299158592, 768850512682, 10664438220, 48325482040, 146064427222, 399719144522, 1058010632332, 19397564493, 70989924483, 204883792787, 552368730897, 4127272583, 31360055575, 102035300196, 285453580169, 761465592132, 10441333753, 47746475595, 144561774556, 395819420123, 1047889963499, 19091127624, 70194651191, 202819878392, 547012405305, 3966062967, 30941680007, 100949520763, 282635736438, 754152648826, 10220465107, 47173271267, 143074179249, 391958773382, 1037870710119, 18789724876, 69412442670, 200789870231, 541744073754, 3806695412, 30528085091, 99876148217, 279850091360, 746923268357, 10002150769, 46606695936, 141603787729, 388142773853, 1027967326352, 18490265571, 68635277779, 198772951171, 536509711863, 3648674112, 30117984164, 98811843402, 277087978900, 739754960399, 9785985038, 46045696942, 140147868236, 384364333153, 1018161416409, 18194286218, 67867144325, 196779470429, 531336176853, 3492522697, 29712735640, 97760131531, 274358548202, 732671469307, 9572703304, 45492182566, 138711373191, 380636302745, 1008486331820, 17900935152, 67105832025, 194803692470, 526208585828, 3337248365, 29309763482, 96714327280, 271644449204, 725627766979, 9360338837, 44941048652, 137281055555, 376924304261, 998852854893, 17611429352, 66354498813, 192853812778, 521148206276, 3184165505, 28912478890, 95683283946, 268968658210, 718683482800, 9149398605, 44393610861, 135860330525, 373237200776, 989283985222, 17322714012, 65605217162, 190909256928, 516101642983, 3031826579, 28517124738, 94657250065, 266305867583, 711772937533, 8941886748, 43855070484, 134462696085, 369610022577, 979870636290, 17037911196, 64866088952, 188991051429, 511123464485, 2882089052, 28128521923, 93648737970, 263688550111, 704980405206, 8736218959, 43321316142, 133077482701, 366015079862, 970540944452, 0};

LL f(LL last){
    return (last + (last >> 20) + 12345LL) & (M - 1);
}
void find_cycle(){
    //Floyd's tortoise and hare algorithm
    LL tortoise = f(s0);
    LL hare = f(f(s0));
    int periode = 1;
    while(hare != tortoise){
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int i = 0;
    tortoise = s0;
    while(tortoise != hare){
        i++;
        tortoise = f(tortoise);
		hare = f(hare);
    }
    tortoise = f(hare);
    while(tortoise != hare){
        tortoise = f(tortoise);
        periode++;
    }
    int start = i;
    cout << periode  << " " << start << endl;
}
LL go(LL s, LL len){
    LL ans = 0;
    for(int i = 0; i < len; i++){
        ans += !(s & 1);
        s = f(s);
    }
    return ans;
}
LL get_before(LL len){
    LL ans = 0;
    for(int i = 0; i < len/block; i++)
        ans+= before[i];
    return ans + go(before_num[len/block],len % block);
}
LL p = 0;
LL get_after(LL len){
    LL ans = 0;
    ans += len/periode * p;
    len  %= periode;
    for(int i = 0; i < len/block; i++)
        ans+= after[i];
    return ans + go(after_num[len/block],len % block);
}
int main(){
   ios_base::sync_with_stdio (0),cin.tie(0);
   for(auto x : after)  p+= x;
    LL n;
    cin >> n;
    if(n == 0) return cout << 0,0;
    n--;
    if(n < start){
        cout << get_before(n + 1) << endl;
        return 0;
    }
    cout << get_before(start) + get_after(n - start + 1);
   }