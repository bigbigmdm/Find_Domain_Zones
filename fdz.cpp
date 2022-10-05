#include<stdio.h> //printf
#include<string.h> //strcpy
#include<sys/socket.h>
#include<netdb.h>	//hostent
#include<arpa/inet.h>
int main(int argc , char *argv[])
{
    char *zones[] = {".ru", ".com", ".info", ".biz", ".pw", ".cyou", ".travel", ".орг", ".net", ".org", ".asia",
		".name", ".cloud", ".academy", ".accoundant", ".accoundants", ".actor", ".adult", ".aero", ".agency",
		".airforce", ".apartments",".app" , ".art", ".associates", ".attorney", ".auction", ".audio", ".auto",
		".baby", ".band", ".bar", ".bargains", ".beauty", ".beer", ".best", ".bet", ".bid", ".bike", ".bingo",
		".black", ".blackfriday", ".blog", ".blue", ".boutique", ".broker", ".builders", ".buisness", ".buzz",
		".bzh", ".cab", ".cafe", ".cam", ".camera", ".camp", ".capital", ".car", ".cards", ".care", ".career",
		".careers", ".cars", ".casa", ".cash", ".casino", ".cat", ".catering", ".caener", ".chat", ".cheap",
		".christmas", ".church", ".city", ".claims", ".cleaning", ".click", ".clinic", ".clothing", ".club",
		".coach", ".codes", ".cofee", ".colledge", ".community", ".company", ".computer", ".condos", ".construction",
		".consulting", ".contractors", ".cooking", ".cool", ".country", ".coupons", ".courses", ".credit", ".creditcard",
		".cricket", ".cyou", ".dance", ".date", ".dating", ".deals", ".degree", ".delivery", ".democrat", ".dental",
		".dentist", ".desi", ".design", ".dev", ".diamonds", ".diet", ".digital", ".direct", ".directory", ".discount",
		".dog", ".domains", ".download", ".earth", ".eco", ".education", ".email", ".energy", ".engineer", ".engineering",
		".equipment", ".estate", ".events", ".exchange", ".expert", ".exposed", ".express", ".fail", ".faith", ".family",
		".fans", ".farm", ".fashion", ".feedback", ".film", ".finance", ".financial", ".fish", ".fishing", ".fit", 
		".fitness", ".flight", ".florist", ".flowers", ".fm", ".football", ".forsale", ".foundation", ".frl", ".fun",
		".fund", ".furniture", ".futbol", ".fyi", ".gallery", ".game", ".games", ".garden", ".gent", ".gift", ".gifts",
		".gives", ".glass", ".global", ".gmbh", ".gold", ".golf", ".graphics", ".gratis", ".green", ".gripe", ".group",
		".guide", ".guitars", ".guru", ".hair", ".haus", ".health", ".healthcare", ".help", ".hiphop", ".hiv", ".hockey",
		".holdings", ".holiday", ".horse", ".hospital", ".host", ".hosting", ".house", ".how", ".icu", ".immo", ".immobilien",
		".industries", ".ink", ".institute", ".insure", ".insure", ".international", ".investments", ".jetzt", ".jewelry",
		".jobs", ".juegos", ".kaufen", ".kim", ".kitchen", ".kiwi", ".land", ".lawyer", ".lease", ".legal", ".lgbt", ".life",
		".lighting", ".limited", ".limo", ".link", ".live", ".llc", ".loan", ".loans", ".lol", ".love", ".ltd", ".ltda", ".luxe",
		".luxury", ".makeup", ".maison", ".management", ".market", ".marketing", ".markets", ".mba", ".media", ".memorial", ".men",
		".menu", ".mobi", ".moda", ".moe", ".money", ".monster", ".movie", ".network", ".ninja", ".observer", ".onl", ".online",
		".ooo", ".page", ".partners", ".parts", ".party", ".pet", ".photo", ".photography", ".photos", ".physio", ".pics",
		".pictures", ".pink", ".pizza", ".plumbing", ".plus", ".poker", ".porn", ".press", ".pro", ".productions", ".promo",
		".properties", ".property", ".protection", ".pub", ".quest", ".qpon", ".racing", ".realty", ".recipes", ".red", ".rehab",
		".reisen", ".rent", ".rentals", ".repair", ".report", ".rest", ".restaurant", ".reviews", ".rip", ".rocks", ".rodeo", ".run",
		".sale", ".salon", ".sarl", ".school", ".schule", ".science", ".security", ".services", ".sex", ".sexy", ".shiksha", ".shoes",
		".shop", ".shopping", ".show", ".singles", ".site", ".ski", ".skin", ".soccer", ".social", ".software", ".solar", ".solutions",
		".soy", ".space", ".storage", ".stone", ".stream", ".studio", ".study", ".sucks", ".supplies", ".supply", ".support", ".surf",
		".surgery", ".systems", ".tatoo", ".tax", ".taxi", ".team", ".tech", ".technology", ".tel", ".tennis", ".theater", ".theatre",
		".tienda", ".tips", ".tires", ".today", ".tools", ".top", ".tours", ".town", ".toys", ".trade", ".trading", ".traning",
		".tube", ".tv", ".university", ".uno", ".vacations", ".ventures", ".vet", ".viajes", ".video", ".villas", ".vin", ".vip",
		".vision", ".vodka", ".vote", ".voto", ".voyage", ".wang", ".watch", ".website", ".webcam", ".wedding", ".whoswho", ".wiki",
		".win", ".wine", ".work", ".works", ".world", ".wtf", ".xxx", ".xyz", ".yoga", ".zone", ".realstate", ".fan", ".cleaning",
		".edu", ".gov", ".post", ".mil",
		".ac", ".ad", ".ae", ".af", ".ag", ".ai", ".al", ".am", ".an", ".ao", ".aq", ".ar", ".as", ".at", ".au", ".aw", ".ax", ".az",
        ".ba", ".bb", ".bd", ".be", ".bf", ".bg", ".bh", ".bi", ".bj", ".bl", ".bm", ".bn", ".bo", ".bq", ".br", ".bs", ".bt",".bv",
        ".bw", ".by", ".bz", ".ca", ".cc", ".cd", ".cf", ".cg", ".ch", ".ci", ".ck", ".cl", ".cm", ".cn", ".co", ".cr", ".cu", ".cv",
        ".cw", ".cx", ".cy", ".cz", ".de", ".dj", ".dk", ".dm", ".do", ".dz", ".ec", ".ee", ".eg", ".eh", ".er", ".es", ".et", ".eu",
        ".fi", ".fj", ".fk", ".fm", ".fo", ".fr", ".ga", ".gb", ".gd", ".ge", ".gf", ".gg", ".gh", ".gi", ".gl", ".gm", ".gn", ".gp",
        ".gq", ".gr", ".gs", ".gt", ".gu", ".gw", ".gy", ".hk", ".hm", ".hn", ".hr", ".ht", ".hu", ".id", ".ie", ".il", ".im", ".in",
        ".io", ".iq", ".ir", ".is", ".it", ".je", ".jm", ".jo", ".jp", ".ke", ".kg", ".kh", ".ki", ".km", ".kn", ".kp", ".kr", ".kw",
        ".ky", ".kz", ".la", ".lb", ".lc", ".li", ".lk", ".lr", ".ls", ".lt", ".lu", ".lv", ".ly", ".ma", ".mc", ".md", ".me", ".mf",
        ".mg", ".mh", ".mk", ".ml", ".mm", ".mn", ".mo", ".mp", ".mq", ".mr", ".ms", ".mt", ".mu", ".mv", ".mw", ".mx", ".my", ".mz",
        ".na", ".nc", ".ne", ".nf", ".ng", ".ni", ".nl", ".no", ".np", ".nr", ".nu", ".nz", ".om", ".pa", ".pe", ".pf", ".pg", ".ph",
        ".pk", ".pl", ".pm", ".pn", ".pr", ".ps", ".pt", ".pw", ".py", ".qa", ".re", ".ro", ".rs", ".rw", ".sa", ".sb", ".sc",
        ".sd", ".se", ".sg", ".sh", ".si", ".sj", ".sk", ".sl", ".sm", ".sn", ".so", ".sr", ".ss", ".st", ".su", ".sv", ".sx", ".sy",
        ".sz", ".tc", ".td", ".tf", ".tg", ".th", ".tj", ".tk", ".tl", ".tm", ".tn", ".to", ".tp", ".tr", ".tt", ".tv", ".tw", ".tz",
        ".ua", ".ug", ".uk", ".um", ".us", ".uy", ".uz", ".va", ".vc", ".ve", ".vg", ".vi", ".vn", ".vu", ".wf", ".ws", ".ye", ".yt",
        ".za", ".zm", ".zw", ".рф"};    
	//char hostname[127] = "yandex";
	char hostname[127];
	char host[127];
	char cur_zone[31];
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list;
	int i, j;
	if (argc < 2)
	{
		printf("Please write the domain name without the domain zone.\n");
		return 1;
	}
	if ((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"--help") == 0))
	{
		printf("fdz - Find Domain Zones. This utility searches all correctly answered domain zones for the domain name.\n Command format: \n fdz <name> \n <name> - is domain name without the domain zone.\n");
		return 1;
	}
	strcpy(hostname, argv[1]);
	printf("Domain Zones Finder v 1.0. The domain zones for host `%s` is:\n", hostname);
	for (j=0;j < sizeof(zones)/sizeof(zones[0]);j++)
	{
	    strcpy(cur_zone, zones[j]);
	    strcpy(host, hostname);
	    strcat(host, cur_zone);
	    //printf ("%s ",host);
		
	    if ( (he = gethostbyname( host ) ) != NULL) 
	    {
	    //Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
	    addr_list = (struct in_addr **) he->h_addr_list;
	
	    for(i = 0; addr_list[i] != NULL; i++) 
	    {
		  //Return the first one;
		  strcpy(ip , inet_ntoa(*addr_list[i]) );
	    }
	    printf("%s resolved to: %s \n" ,host , ip);
	}
	
	   
    }
	return 0;
}
