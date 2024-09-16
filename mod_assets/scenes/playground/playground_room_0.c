#include "playground_scene.h"


/**
 * Header Child Day (Default)
*/
#define LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST 3
#define LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST 2
SceneCmd playground_room_0_header00[] = {
    SCENE_CMD_ROOM_SHAPE(&playground_room_0_shapeHeader),
    SCENE_CMD_ECHO_SETTINGS(0x00),
    SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(false, false),
    SCENE_CMD_TIME_SETTINGS(255, 255, 10),
    SCENE_CMD_OBJECT_LIST(LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST, playground_room_0_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST, playground_room_0_header00_actorList),
    SCENE_CMD_END(),
};

s16 playground_room_0_header00_objectList[LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST] = {
    OBJECT_NUL_BOX,
    OBJECT_TROLOLO,
    OBJECT_KANBAN,
};

ActorEntry playground_room_0_header00_actorList[LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST] = {
    // Square Signpost
    {
        /* Actor ID   */ ACTOR_EN_KANBAN,
        /* Position   */ { 70, -80, 270 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(180.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0001
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_THE_DEV,
        /* Position   */ { 250, -100, 190 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(270.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },
};

RoomShapeNormal playground_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(playground_room_0_shapeDListsEntry),
    playground_room_0_shapeDListsEntry,
    playground_room_0_shapeDListsEntry + ARRAY_COUNT(playground_room_0_shapeDListsEntry)
};

RoomShapeDListsEntry playground_room_0_shapeDListsEntry[1] = {
    { playground_room_0_shapeHeader_entry_0_opaque, NULL }
};

Gfx playground_room_0_shapeHeader_entry_0_opaque[] = {
	gsSPDisplayList(playground_room_0_dl_ground_mesh_layer_Opaque),
	gsSPDisplayList(playground_room_0_dl_wall_0_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

u64 playground_room_0_dl_grassGround_tex_rgba16_ci8[] = {
	0x0001020304050607, 0x0809030a0b0c060d, 0x030e0f1011020f01, 0x120e081308031415, 0x000116120717060e, 0x0701091819120706, 0x1a0c011201071b18, 0x0101170008061c1d, 
	0x1e0000011b160e0e, 0x0c1a0f1a121f0e09, 0x0101011b1b082004, 0x1b050103011b0621, 0x0000221708161a12, 0x0323240c0c04120f, 0x120e0c12040e2507, 0x201b010e03182627, 
	0x0c0c240c1a0f1c0f, 0x0f1a012816192925, 0x2a001b062b12011b, 0x01010e0f270e0412, 0x0f2c0312111c1a03, 0x100c121901161c0f, 0x2a2d1b120d051b04, 0x2e2f0d280f010520, 
	0x231a0e18012c010c, 0x100e0803121b2416, 0x04042329300e0303, 0x0e0e0119281a010c, 0x310f12071904070e, 0x0f01040b0c121216, 0x0104122724021a1c, 0x14110316040f1a0f, 
	0x0e320201081b0a0e, 0x28191a2312011b05, 0x220a07010f1a0b0f, 0x1114293319340107, 0x2a02161218013536, 0x1b1209241b18181b, 0x0a01160317191922, 0x1b37381a1a09391e, 
	0x06002f200111020c, 0x0103280e3a1f1203, 0x0a04100a0e381200, 0x042f190c020e0d06, 0x0d2e2d1b090e0c29, 0x102801280c030e35, 0x01063a3a031b1b1a, 0x0a2e0d120f011203, 
	0x042e170c16180416, 0x0f080d010c1f0101, 0x1a1b3a331b22010e, 0x0e24280401161a1a, 0x0608161035123b0e, 0x160608011c1a0b21, 0x3c3d2929030a2a16, 0x2b2a180804350901, 
	0x0504011a38092d06, 0x0104120f101a0c0f, 0x021c293516191812, 0x063e0504160e000d, 0x05000d353508051b, 0x2e06010c3528241a, 0x193f3f0227120601, 0x002d2d1704040e18, 
	0x0712120c012f001b, 0x081a080416261114, 0x330e0c02250c1b12, 0x0e000012062b0800, 0x040e160400170e16, 0x091b0d0c020e1603, 0x0301282716240e09, 0x041b16122b010101, 
	0x040606352a0e1c24, 0x1b00061a1a352a18, 0x0119240b1b08033a, 0x2f2b011218382401, 0x2911160e01382904, 0x060a030e15162a24, 0x0119401941190c19, 0x2410152401190c0e, 
	0x0f2916082b0e0142, 0x00080c0f100e2b0e, 0x1c1a1a1822011c0c, 0x0c1c161204090819, 0x43290b0408050406, 0x2d2d0e0c160d0535, 0x100c033a081b0e19, 0x120e1a16440c0f2c, 
	0x0f150c0112010645, 0x0d040d3e1e2d0600, 0x1b1b1712191a2512, 0x0a171f192c1a271a, 0x350c0c1b1f120600, 0x120704173e360e1b, 0x0a2b06010c0f0c19, 0x0e18190e01272424, 
	0x16160c09042e1827, 0x0101012e46202a1a, 0x212b000101123a0e, 0x030c1a1601120c0e, 0x2c010e0e001b0431, 0x101a3504472e0e11, 0x0e0818012309010e, 0x041b162416043a10, 
	0x0a0e012a040c010d, 0x230c0e010746000e, 0x0e01120348161617, 0x0d060d081a012f24, 0x0e3803160f0c1a03, 0x120e1b060c06062a, 0x03190a03011b120a, 0x2c0e0109240a0c48, 
	0x0e0e0124380f0c17, 0x031c040701120e00, 0x0e42050018072e01, 0x0c010101040e0f0c, 0x03010919013f2412, 0x0f210e24120e1b05, 0x22050407072b2d18, 0x0408080401100c25, 
	0x0b0f181216480c0c, 0x151a07230a080500, 0x070a1b2a2b08050d, 0x1b4918010110241b, 0x150f3a1912061b16, 0x110c0a2529042d2f, 0x200c014a1b04071a, 0x0c231f081b160304, 
	
};

u64 playground_room_0_dl_grassGround_tex_rgba16_pal_rgba16[] = {
	0x851563cf29c5538d, 0x6c518d577c937451, 0x7cd55bcd640f3247, 0x4b0b84d55b8d3a87, 0x3a4732056c118557, 0x11031943534b7cd3, 0x74535bcf42c97493, 0x218510c195576c53, 
	0x7491218385174b4b, 0x534d4ac97c954289, 0x5b8f2a056c0f8d17, 0x4acb9dd7959795d7, 0x638d42871903430b, 0x42c74b0963cd21c5, 0x32457c91641195d5, 0x19833ac98d153a89, 
	0x42cb6c938d973a45, 0x3ac79e178d5584d3, 0x430974d36bcf0000
};

u64 playground_room_0_dl_stoneBorder_tex_ci4_ci4[] = {
	0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0012313300000000, 0x0000000000000000, 0x0000000000000000, 
	0x0000000000000000, 0x3222223330000000, 0x0000000000000000, 0x0000000024100000, 0x4440000000325256, 0x3117222528500033, 0x3133000000002222, 0x2220002231220222, 
	0x14122002525995a5, 0x8614433369b99336, 0x6553100000222224, 0x44122229333b6532, 0x5555235bb39bbcb9, 0x961443336b955955, 0x5395225222584111, 0x143a535ba6aab663, 
	0xc9cb59bcc9ab9bc9, 0x861443638b8b55cb, 0x9c552412acc31166, 0x1337411caa856c6c, 0xbbb533555abcc8cb, 0x981438838baacbab, 0x5524413816ca3839, 0xc811436ccb644436, 
	0x6b9236339acc83bc, 0x1314bb839aaccbb5, 0x6613199b838ac38a, 0xbcc338a95ca1418b, 0x652118631bcc619c, 0xb139bc93ccacc59b, 0x1913cc8111159bc1, 0x11bbbb9369a33196, 
	0x3931888338a6325a, 0x8339bc99accbc5cb, 0xcbb8bbb338b5c933, 0x319bc96163693393, 0xb833bb8119a3333c, 0xa963cc6ac953a5bb, 0xbcb38bbb3b9aa983, 0x339cb96339b11333, 
	0xa943db9318b63638, 0xac6bcccaa618abac, 0xab3136eea9ac8c56, 0x9bcbb9961b99336b, 0xa91cccbb6abb8866, 0xac96cccc9633accc, 0xa96131aeaacaacbc, 0xaaacc9b91cc9699a, 
	0xaa8acccb9eecb9ba, 0xaa69cbaccb36ccac, 0xbbccb36eaaeeacaa, 0xcccbcbbb3aa39cba, 0xbabaccccbeeebbaa, 0xea66baaab9bbaacc, 0xb9ccc9baaaaeeacb, 0x8bacc1cb3ac8bca3, 
	0x8aaeaccccaeeebaa, 0xeeb6ccaccbacaaab, 0x96b9bcaaaaacaaa6, 0x3baa611b9aebc993, 0x6baeeeaaacaeecaa, 0xeebbcaacbaebaaec, 0x869bcaaaaccb6666, 0x6aae666caaeec963, 
	0x689aeeeeeaaeeeac, 0xeeebccabcaeaceee, 0xcbbccacaaaccbcb1, 0x1caeb96aaaaecb36, 0x69baeeeac9baeaaa, 0xeeecbabaaaeaaeee, 0xccccccaaaaabac38, 0xbcaeeb6aaafeecb9, 
	0xbcbaeeaacbcaeaaa, 0xeeebbcbaaeeaaaee, 0xeccbcb19cacaeacb, 0x9baaeb9aaafaeec9, 0xb9baaeacb9aaeaaa, 0xeeebbcaaaaeaaaae, 0xebccc6619acceab6, 0x6caaeebaaaeaaeeb, 
	0xbcaaacec68caaaaa, 0xaeecbbaaacdaaaaa, 0xeeecccb6bccceecb, 0xbcaaaeeaaaeeafea, 0xaaaaeaebbccaaaaa, 0xaeeebaaaacceeaac, 0xaaeecacbcaabae99, 0xcaaaaaaaafaaeace, 
	0xaaaaeaeccccceacc, 0xceaaaaafcbcefadd, 0xeaaeecbbbeecaeea, 0xbaacbaaaaeaaefcc, 0xaacaaaeaccaeaccd, 0xdccaaaacdbcffcdd, 0xfafaeee9caeeaaee, 0xaaccccaaaaaafeca, 
	0xecccaaeeaaaeaccc, 0xdbbcaaacddafffcd, 0x9aaaaee9aaaefaaa, 0xaaccbbaaeaaeeaca, 0xaccaaaaeaaaeeaaa, 0xcdbcabcaccafedbb, 0x8aeaaeebaaaaaaaa, 0xaacaccaaecaeeeaa, 
	0xaccacaaaaaaaeeff, 0xccbbceaabdaaadbd, 0x9cfaaaaaaaaaaaab, 0xdacaacaefaaefeef, 0xaaaaaaaaaadcaefa, 0xaa8bdffacbdaadcb, 0x9dfececaaaaacadd, 0xdaaaaaefaacaeeaa, 
	0xaaacabacabbbcaae, 0xac69bdaaccacaac9, 0xbcafaccaafdb9bb9, 0x9dfec9aaaacdcac9, 0xfafacbdacbbbbdaa, 0xca689badacccaad9, 0x9bdafaeeaab98cd8, 0x9caecdacacabac99, 
	0xcacaacdccdbbbcaa, 0xcb688bcadddbcac9, 0x899caefaacdcbbd9, 0x9dafcbacaaa9ccb9, 0xbccacddddbbb9caa, 0xac668ddc99b9acc9, 0x88bcaaeaaacccdd9, 0x9caacbcccfab9bb9, 
	0xbccacdddddbbbcac, 0xcc668bdc89dbdac9, 0x86bdaaaaacccddb9, 0x8daab9ccfaadbb99, 0xbccacdd9ddccbcca, 0xab6889bd89bbdfe9, 0x968caaaaaacdbb99, 0xbcaa9bbaeaacd999, 
	0xcccacdd98bbcccad, 0xcb688bdb8bbbdae9, 0x99bccaaaeedb9b98, 0xbdfa9bdceeaad999, 0xbcacacc988ccdcad, 0xcdb88bdcbcdddfe9, 0x9dbcaaaaeecb9888, 0x9aef99bceeffd999, 
	0xbbaaffd988ddb9bb, 0xcdb888cacacdaff9, 0xdbd89aaaeeac9998, 0x9caabbbaeeaab988, 0xbccaeab998ccdd9b, 0xccbbddafafaaff99, 0xcddd9aaaaeaacb9b, 0xdaaadbcfeaadb998, 
	0xbdbaecb998bdcb98, 0xcabdccfffefaaaad, 0xccbbddaacacaad9b, 0xcdccaddeaacb9999, 0x9bbaadb9989bdb98, 0xcc9bcafffaafadcd, 0xcdb9bdaaca9cccbc, 0xcdccccbeadbb9999, 
	0xdddcabb8999bcd98, 0xcadb9caaaaaacccd, 0xdd99ddaadb9cacbb, 0xdbcaacbaacbbbb99, 0xcdacbdb8998ccb98, 0xccad9caacccccacd, 0xd999ddadd8ccaa99, 0x89aadcdacbdd98bd, 
	0xbbcddbd8899dad98, 0xbca98baeadccaccd, 0xb969ddddd8bccab9, 0x8daccdcacdcdbb9b, 0xbddbdbd889bdcb99, 0xbdac99faabccaccd, 0xb889dadd889cafb9, 0x9acaacaaccfdbbdd, 
	0xbdd9bd9899bbdb99, 0x8bacdbfedbdccabb, 0x88869aad889bca99, 0xbacdccaacdacbddb, 0xcdb9bb988bbbcb99, 0x8dacdaefc9daaa99, 0x88869aad889bcd99, 0xcecdcacaccaacdcd, 
	0xddb9b9988bbbb999, 0xbdcadaffc9cacc9b, 0x98889add88bbccbb, 0xceabdcaacdacaccd, 0xdc9dbb98bdcdbb99, 0x9ccccaafc9aaacbb, 0xb9899ad8899daada, 0xdefbdaaaccfeaacd, 
	0xccbbdcd9dcacdc9b, 0xddacafaabcacccbb, 0xb9899ad899dddaaa, 0xdaadddaadceefacc, 0xaaddceccdcfccc9b, 0xddacaeaddcaacc99, 0xbb99dad999ddcaea, 0xdacdddaacceefacc, 
	0xaadcfefcdaffacbb, 0xddcdaecdcdaaadb9, 0xbdb9dadb99cdcaea, 0xbccddcccdcaeeccc, 0xaccceeaadaefcc9c, 0xdbbafcccdcaacbb9, 0x9dbbbadb9bcdcaec, 0xccccdacacdfefaca, 
	0xfcccffccdaffcbdc, 0xcd9aaacadaaadddb, 0xbbdbbadb9bddcaac, 0xccccccaaccfeeaca, 0xaccceaacdaaacdaa, 0xcbdacacaccacccbb, 0xddccbadb9dcccaad, 0xcdccccccccaeefaa, 
	0xacccaacccaaaccfa, 0xcddcaaacacacadd9, 0x9ddcdabb9bcccccb, 0xcccaaaaacccaeeaa, 0xaacacacccacaaaff, 0xcddccfaacaaaaddd, 0xbbdccdddd123133b, 0xddaacaacaccceffa, 
	0xacccacaaafaacaa2, 0x41caafacaafccddc, 0xccdacdd322222333, 0xdaaaaaaacacaaeef, 0xaac2222222aca223, 0x122e222444faaccc, 0xc325256311722252, 0x851ae133133cefee, 
	0xf222224444222293, 0x33b653241422aa25, 0x25995a5861443336, 0x9b9933865531efee, 0x2584111143a535ba, 0x6aab3635555235bb, 0x39bbcb9961443336, 0xb955955539522522, 
	0xcc311661337411ca, 0xa856c6cc9cb59bcc, 0x9ab9bc9861443638, 0xb8b55cb9c552412a, 0x6ca3839c811436cc, 0xb644436bbb533555, 0xabcc8cb981438838, 0xbaacbab552441381, 
	
};

u64 playground_room_0_dl_stoneBorder_tex_ci4_pal_rgba16[] = {
	0xdef2c62db65d9cdf, 0xdef395d39499ffff, 0x8415739339c962cf, 0x4a4d5a8f29473189, 
};

Vtx playground_room_0_dl_ground_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-300, -170, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -80, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -80, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -170, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -170, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -80, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -80, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -170, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx playground_room_0_dl_ground_mesh_layer_Opaque_vtx_0[54] = {
	{{ {-300, -170, -188}, 0, {2169, 1435}, {237, 121, 221, 255} }},
	{{ {-300, -120, -58}, 0, {2153, 680}, {237, 121, 221, 255} }},
	{{ {9, -120, -131}, 0, {466, 1090}, {237, 121, 221, 255} }},
	{{ {-159, -170, -203}, 0, {1412, 1523}, {237, 121, 221, 255} }},
	{{ {-83, -170, -300}, 0, {997, 2046}, {237, 121, 221, 255} }},
	{{ {140, -120, -300}, 0, {-242, 2029}, {237, 121, 221, 255} }},
	{{ {-300, -170, -188}, 0, {2207, 1519}, {0, 127, 0, 255} }},
	{{ {-159, -170, -203}, 0, {1442, 1555}, {0, 127, 0, 255} }},
	{{ {-83, -170, -300}, 0, {997, 2046}, {0, 127, 0, 255} }},
	{{ {-300, -170, -300}, 0, {2173, 2114}, {0, 127, 0, 255} }},
	{{ {227, -120, 300}, 0, {-795, -1266}, {63, 104, 219, 255} }},
	{{ {163, -120, 181}, 0, {-264, -796}, {63, 104, 219, 255} }},
	{{ {127, -80, 241}, 0, {-180, -1048}, {63, 104, 219, 255} }},
	{{ {166, -80, 300}, 0, {-400, -1345}, {63, 104, 219, 255} }},
	{{ {166, -80, 300}, 0, {-400, -1345}, {253, 127, 249, 255} }},
	{{ {127, -80, 241}, 0, {-180, -1048}, {253, 127, 249, 255} }},
	{{ {50, -87, 221}, 0, {211, -906}, {253, 127, 249, 255} }},
	{{ {14, -80, 300}, 0, {415, -1340}, {253, 127, 249, 255} }},
	{{ {-83, -170, -300}, 0, {997, 2046}, {239, 125, 13, 255} }},
	{{ {140, -120, -300}, 0, {-242, 2029}, {239, 125, 13, 255} }},
	{{ {140, -120, -500}, 0, {-256, 3092}, {239, 125, 13, 255} }},
	{{ {-83, -130, -500}, 0, {935, 3128}, {239, 125, 13, 255} }},
	{{ {-300, -170, -300}, 0, {2173, 2114}, {0, 125, 25, 255} }},
	{{ {-83, -170, -300}, 0, {997, 2046}, {0, 125, 25, 255} }},
	{{ {-83, -130, -500}, 0, {935, 3128}, {0, 125, 25, 255} }},
	{{ {-300, -130, -500}, 0, {2111, 3196}, {0, 125, 25, 255} }},
	{{ {227, -120, 300}, 0, {-795, -1266}, {0, 127, 0, 255} }},
	{{ {300, -120, 300}, 0, {-1191, -1256}, {0, 127, 0, 255} }},
	{{ {300, -120, -500}, 0, {-1091, 3132}, {0, 127, 0, 255} }},
	{{ {163, -120, 181}, 0, {-264, -796}, {0, 127, 0, 255} }},
	{{ {38, -120, 123}, 0, {450, -454}, {0, 127, 0, 255} }},
	{{ {-300, -120, 300}, 0, {2173, -1278}, {0, 127, 0, 255} }},
	{{ {300, -120, -500}, 0, {-1091, 3132}, {0, 127, 0, 255} }},
	{{ {9, -120, -131}, 0, {466, 1090}, {0, 127, 0, 255} }},
	{{ {-300, -120, 300}, 0, {2173, -1278}, {0, 127, 0, 255} }},
	{{ {140, -120, -300}, 0, {-242, 2029}, {0, 127, 0, 255} }},
	{{ {140, -120, -500}, 0, {-222, 3117}, {0, 127, 0, 255} }},
	{{ {-300, -120, -58}, 0, {2153, 680}, {0, 127, 0, 255} }},
	{{ {-71, -120, 300}, 0, {921, -1291}, {0, 127, 0, 255} }},
	{{ {38, -120, 123}, 0, {450, -454}, {0, 127, 0, 255} }},
	{{ {140, -120, -500}, 0, {-222, 3117}, {254, 127, 1, 255} }},
	{{ {300, -120, -500}, 0, {-1091, 3132}, {254, 127, 1, 255} }},
	{{ {300, -120, -620}, 0, {-1079, 3791}, {254, 127, 1, 255} }},
	{{ {-300, -130, -500}, 0, {2166, 3128}, {254, 127, 1, 255} }},
	{{ {-300, -130, -620}, 0, {2177, 3734}, {254, 127, 1, 255} }},
	{{ {-83, -130, -500}, 0, {988, 3149}, {254, 127, 1, 255} }},
	{{ {127, -80, 241}, 0, {-180, -1048}, {16, 115, 205, 255} }},
	{{ {163, -120, 181}, 0, {-264, -796}, {16, 115, 205, 255} }},
	{{ {38, -120, 123}, 0, {282, -332}, {16, 115, 205, 255} }},
	{{ {50, -87, 221}, 0, {211, -906}, {16, 115, 205, 255} }},
	{{ {50, -87, 221}, 0, {211, -906}, {205, 112, 224, 255} }},
	{{ {38, -120, 123}, 0, {282, -332}, {205, 112, 224, 255} }},
	{{ {-71, -120, 300}, 0, {921, -1291}, {205, 112, 224, 255} }},
	{{ {14, -80, 300}, 0, {415, -1340}, {205, 112, 224, 255} }},
};

Gfx playground_room_0_dl_ground_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(playground_room_0_dl_ground_mesh_layer_Opaque_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 29, 26, 28, 0),
	gsSP2Triangles(30, 29, 28, 0, 28, 31, 30, 0),
	gsSPVertex(playground_room_0_dl_ground_mesh_layer_Opaque_vtx_0 + 32, 22, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 1, 5, 2, 0),
	gsSP2Triangles(2, 6, 7, 0, 8, 9, 10, 0),
	gsSP2Triangles(8, 10, 11, 0, 10, 12, 11, 0),
	gsSP2Triangles(11, 13, 8, 0, 14, 15, 16, 0),
	gsSP2Triangles(14, 16, 17, 0, 18, 19, 20, 0),
	gsSP1Triangle(18, 20, 21, 0),
	gsSPEndDisplayList(),
};

Vtx playground_room_0_dl_wall_0_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-300, -170, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, 100, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, 100, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -170, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -170, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, 100, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, 100, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -170, -620}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx playground_room_0_dl_wall_0_mesh_layer_Opaque_vtx_0[24] = {
	{{ {-300, -120, 300}, 0, {-11, 2037}, {127, 0, 0, 255} }},
	{{ {-300, -120, -58}, 0, {2545, 2033}, {127, 0, 0, 255} }},
	{{ {-300, 100, -58}, 0, {2545, -25}, {127, 0, 0, 255} }},
	{{ {-300, 100, 300}, 0, {-11, -21}, {127, 0, 0, 255} }},
	{{ {-300, 100, -58}, 0, {-16, -16}, {127, 0, 0, 255} }},
	{{ {-300, -120, -58}, 0, {-16, 2026}, {127, 0, 0, 255} }},
	{{ {-300, -170, -188}, 0, {970, 2032}, {127, 0, 0, 255} }},
	{{ {-300, 50, -188}, 0, {1000, -25}, {127, 0, 0, 255} }},
	{{ {-300, -170, -298}, 0, {1830, 2044}, {127, 0, 0, 255} }},
	{{ {-300, 50, -298}, 0, {1860, -12}, {127, 0, 0, 255} }},
	{{ {-300, -120, 300}, 0, {-11, 2037}, {0, 0, 129, 255} }},
	{{ {-300, 100, 300}, 0, {-11, -21}, {0, 0, 129, 255} }},
	{{ {300, 100, 300}, 0, {-4300, -21}, {0, 0, 129, 255} }},
	{{ {300, -120, 300}, 0, {-4300, 2037}, {0, 0, 129, 255} }},
	{{ {300, -120, 300}, 0, {-4300, 2037}, {129, 0, 0, 255} }},
	{{ {300, 100, 300}, 0, {-4300, -21}, {129, 0, 0, 255} }},
	{{ {300, 100, -620}, 0, {-10878, -21}, {129, 0, 0, 255} }},
	{{ {300, -120, -620}, 0, {-10878, 2037}, {129, 0, 0, 255} }},
	{{ {-300, 50, -298}, 0, {-21, -12}, {127, 0, 0, 255} }},
	{{ {-300, -170, -298}, 0, {0, 2019}, {127, 0, 0, 255} }},
	{{ {-300, -130, -498}, 0, {2039, 2036}, {127, 0, 0, 255} }},
	{{ {-300, 90, -498}, 0, {2069, -33}, {127, 0, 0, 255} }},
	{{ {-300, -130, -618}, 0, {3293, 2055}, {127, 0, 0, 255} }},
	{{ {-300, 90, -618}, 0, {3323, -15}, {127, 0, 0, 255} }},
};

Gfx playground_room_0_dl_wall_0_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(playground_room_0_dl_wall_0_mesh_layer_Opaque_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(21, 20, 22, 0, 21, 22, 23, 0),
	gsSPEndDisplayList(),
};

Gfx mat_playground_room_0_dl_grass_layerOpaque[] = {
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, playground_room_0_dl_grassGround_tex_rgba16_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 74),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, playground_room_0_dl_grassGround_tex_rgba16_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_playground_room_0_dl_walls_layerOpaque[] = {
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, playground_room_0_dl_stoneBorder_tex_ci4_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 15),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, playground_room_0_dl_stoneBorder_tex_ci4_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx playground_room_0_dl_ground_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(playground_room_0_dl_ground_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_playground_room_0_dl_grass_layerOpaque),
	gsSPDisplayList(playground_room_0_dl_ground_mesh_layer_Opaque_tri_0),
	gsSPEndDisplayList(),
};

Gfx playground_room_0_dl_wall_0_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(playground_room_0_dl_wall_0_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_playground_room_0_dl_walls_layerOpaque),
	gsSPDisplayList(playground_room_0_dl_wall_0_mesh_layer_Opaque_tri_0),
	gsSPEndDisplayList(),
};

