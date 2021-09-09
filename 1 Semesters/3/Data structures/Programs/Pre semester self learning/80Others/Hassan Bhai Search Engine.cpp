// Search Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "ctime"
using namespace std;

int Start_Time;

string a[1269] = { "atherosclerosis", "anticompetitive", "autocorrelation", "anticholinergic", "acclimatization", "anthropocentric", "agranulocytosis", "aluminosilicate", "assimilationism", "archaebacterium", "adenohypophysis", "antepenultimate", "acetophenetidin", "antivivisection", "autotransformer", "acanthocephalan", "anthropopathism", "ancylostomiasis", "ariboflavinosis", "assertivenesses", "arteriographies", "antispeculation", "apolipoproteins", "archiepiscopate", "anthropophagies", "antiabortionist", "anticlimactical", "affordabilities", "ambisexualities", "amorphousnesses", "authentications", "accessibilities", "acculturational", "agriculturalist", "ambitiousnesses", "amphitheatrical", "anthropological", "antimonarchical", "antiquarianisms", "antiseparatists", "arrondissements", "autobiographies", "autotransfusion", "accountableness", "advisablenesses", "applicabilities", "astronautically", "attentivenesses", "autographically", "apocalyptically", "apprenticeships", "atheroscleroses", "authoritatively", "automatizations", "anthropomorphic", "accountantships", "aerodynamically", "autoradiography", "autotetraploidy", "aerosolizations", "agribusinessman", "algorithmically", "anagrammatizing", "antiferromagnet", "agribusinessmen", "anonymousnesses", "antisegregation", "antituberculous", "anthropophagous", "azidothymidines", "accommodational", "adversarinesses", "allotetraploids", "alphabetization", "alternativeness", "analyzabilities", "aromatherapists", "acknowledgments", "adenocarcinomas", "autotrophically", "associationists", "archaeopteryxes",
"administration", "accomplishment", "aforementioned", "acknowledgment", "anesthesiology", "adenocarcinoma", "antidepressant", "apolipoprotein", "antiarrhythmic", "anticonvulsant", "antiperspirant", "antineoplastic", "arrondissement", "adrenocortical", "antimetabolite", "apocalypticism", "aminopeptidase", "administratrix", "architectonics", "azidothymidine", "automatization", "archiepiscopal", "autoradiograph", "aeroelasticity", "achondroplasia", "associationism", "antiphlogistic", "abstractionism", "autosuggestion", "ammonification", "antiderivative", "anthropophagus", "anticensorship", "annexationists", "allopolyploids", "aggrandizement", "antiepileptics", "antimilitarist", "appendicectomy", "approximations", "anticonvulsive", "anthropometric", "antigovernment", "aphoristically", "apostrophizing", "apparentnesses", "astrobiologist", "arboricultural", "ascertainments", "achromatically", "actualizations", "acceleratingly", "accountability", "actinomorphies", "actinomycetous", "administrating", "acetifications", "alliteratively", "alloantibodies", "apoplectically", "apprehensively", "articulateness", "astrobiologies", "abstractedness", "antepenultimas", "antiliberalism", "allopolyploidy", "ambassadresses", "anathematizing", "ankylosauruses", "affectionately", "aggressiveness", "accomplishable", "accursednesses", "acknowledgedly", "anticorrosives", "antihomosexual", "antimonarchist", "antisocialists", "antitechnology", "abortivenesses", "accidentalness", "accreditations", "aerodynamicist", "affectednesses", "afforestations", "allelomorphism",
"anagrammatical", "analphabetisms", "anaphrodisiacs", "archaebacteria", "accommodations", "apostrophising", "appreciatively", "administrator", "accommodation", "authoritative", "advertisement", "authorization", "accreditation", "appropriation", "autobiography", "accommodating", "authoritarian", "amplification", "accompaniment", "assemblywoman", "approximation", "antimicrobial", "antibacterial", "argumentative", "apportionment", "acculturation", "antipsychotic", "acrylonitrile", "acetaminophen", "acetylcholine", "argumentation", "agglomeration", "accelerometer", "antisubmarine", "anthropogenic", "amniocentesis", "adventuresome", "anticoagulant", "armamentarium", "antihistamine", "arteriovenous", "audiocassette", "agglutination", "antiterrorist", "architectonic", "aspergillosis", "archbishopric", "autochthonous", "abortifacient", "antipersonnel", "aggiornamento", "amitriptyline", "anthropometry", "arteriography", "anticlockwise", "archaeopteryx", "arboriculture", "archimandrite", "antispasmodic", "antinomianism", "antipollution", "atherogenesis", "asthenosphere", "anthraquinone", "antiparasitic", "assistantship", "antidiarrheal", "antisymmetric", "anthroposophy", "ambidexterity", "antisatellite", "autoradiogram", "anticollision", "antirejection", "apprehensible", "aminophylline", "adrenalectomy", "argentiferous", "autocephalous", "actinomycosis", "antifertility", "autocatalysis", "aeromechanics", "agglutinative", "animadversion", "anisometropia", "antilogarithm", "aminoaciduria", "anagrammatize", "autoinfection", "amphiprostyle", "archidiaconal",
"affenpinscher", "anfractuosity", "antiscorbutic", "aldosteronism", "allopolyploid", "actinomorphic", "autopolyploid", "administrated", "adversenesses", "aerobiologies", "agamospermies", "accommodators", "acquiescences", "amusingnesses", "anachronistic", "amortization", "architecture", "announcement", "acknowledged", "appreciation", "accomplished", "anticipation", "acceleration", "accumulation", "advantageous", "authenticity", "anthropology", "acquaintance", "apprehension", "assimilation", "articulation", "astronomical", "appreciative", "alphabetical", "amalgamation", "astonishment", "affectionate", "apprehensive", "amphitheater", "asymptomatic", "afterthought", "augmentation", "aromatherapy", "alphanumeric", "agribusiness", "annihilation", "acquiescence", "approachable", "authenticate", "abbreviation", "astrophysics", "angiogenesis", "antithetical", "aerodynamics", "astronautics", "amelioration", "annunciation", "agrochemical", "arsenopyrite", "appendicitis", "alliteration", "administrate", "appendectomy", "acetaldehyde", "antiaircraft", "aspirational", "antimalarial", "accumulative", "azathioprine", "atmospherics", "augmentative", "anticlerical", "aestheticism", "alliterative", "adventitious", "acetonitrile", "agrichemical", "artilleryman", "antiabortion", "ambidextrous", "auscultation", "anthelmintic", "abolitionism", "antifeminist", "alimentation", "antiparallel", "agroforestry", "antediluvian", "assimilative", "antipathetic", "astrobiology", "axisymmetric", "autoantibody", "aesthetician", "aforethought", "autorotation", "antiparticle",
"androcentric", "atheoretical", "achlorhydria", "apperception", "antineutrino", "argillaceous", "antibusiness", "appurtenance", "archdeaconry", "antitakeover", "aestheticize", "autoxidation", "accouterment", "actinomycete", "apochromatic", "appendicular", "anchorperson", "appropriable", "application", "association", "appropriate", "alternative", "acquisition", "advertising", "appointment", "achievement", "accordingly", "arrangement", "agriculture", "anniversary", "accommodate", "acknowledge", "advancement", "approximate", "accountable", "atmospheric", "arbitration", "accelerator", "abstraction", "adolescence", "affirmation", "affirmative", "adventurous", "archaeology", "ambivalence", "aristocracy", "abnormality", "attribution", "associative", "appreciable", "aeronautics", "absenteeism", "apocalyptic", "acupuncture", "adversarial", "archipelago", "angioplasty", "accumulator", "aerodynamic", "aftermarket", "aggravation", "assemblyman", "archdiocese", "allegorical", "acrimonious", "antislavery", "altercation", "acquisitive", "anachronism", "angiography", "anaesthetic", "antioxidant", "assassinate", "arthroscopy", "appellation", "antiquarian", "appeasement", "addressable", "anaesthesia", "angiotensin", "alternation", "abomination", "astigmatism", "aphrodisiac", "antidumping", "androgynous", "aerosolized", "amphetamine", "amoxicillin", "aquaculture", "aboveground", "approbation", "affectation", "anaphylaxis", "academician", "anastomosis", "accompanist", "ahistorical", "acclamation", "anisotropic", "accessorize", "agnosticism", "aspergillus",
"agglomerate", "acupressure", "amyloidosis", "acquiescent", "adventurism", "agoraphobia", "abortionist", "apologetics", "advertorial", "assignation", "antipoverty", "antinuclear", "afterburner", "antechamber", "acclimation", "accounting", "assessment", "acceptance", "assistance", "attractive", "appearance", "absolutely", "aggressive", "atmosphere", "acceptable", "accessible", "applicable", "appreciate", "anticipate", "adjustment", "assumption", "attendance", "assignment", "altogether", "automation", "accelerate", "artificial", "affordable", "attraction", "automotive", "accountant", "absorption", "ambassador", "accustomed", "accomplish", "attachment", "adaptation", "autonomous", "administer", "automobile", "archbishop", "aggression", "accidental", "articulate", "attainment", "adolescent", "alteration", "admiration", "assortment", "admittedly", "allegiance", "ammunition", "accumulate", "anesthesia", "accordance", "auditorium", "apprentice", "antibiotic", "aesthetics", "arithmetic", "alienation", "actionable", "allegation", "acquainted", "accusation", "ambulatory", "aspiration", "alcoholism", "anatomical", "ambivalent", "autoimmune", "assimilate", "aboriginal", "anticancer", "arbitrator", "asymmetric", "auctioneer", "assemblage", "adrenaline", "antiquated", "antagonism", "anesthetic", "appendices", "abstinence", "authorship", "antagonist", "antithesis", "aberration", "accomplice", "astronomer", "ascendancy", "abstracted", "apocalypse", "apologetic", "archdeacon", "antifungal", "antiseptic", "amphibious", "admissible", "adventurer", "affliction",
"accentuate", "aristocrat", "annotation", "antebellum", "available", "agreement", "advantage", "attention", "authority", "afternoon", "assistant", "assurance", "affecting", "automatic", "aggregate", "analytics", "allowance", "associate", "alongside", "attending", "admission", "alexander", "abandoned", "amendment", "aerospace", "apartment", "architect", "adventure", "ambitious", "appealing", "anonymous", "affiliate", "aesthetic", "authentic", "appraisal", "accompany", "alternate", "applicant", "academics", "ambulance", "attribute", "animation", "apparatus", "aftermath", "affection", "assertion", "arbitrary", "appliance", "alignment", "attendant", "amusement", "abundance", "algorithm", "arthritis", "ambiguous", "alcoholic", "advertise", "addiction", "adjoining", "ancillary", "alleviate", "ambiguity", "athletics", "adherence", "avoidance", "abdominal", "artillery", "amplifier", "appalling", "ascertain", "analogous", "augmented", "accessory", "auxiliary", "adaptable", "abolition", "allotment", "admirable", "aluminium", "addictive", "arrogance", "antivirus", "anonymity", "anomalous", "advisable", "accession", "apologize", "argentine", "antitrust", "apartheid", "astronomy", "accretion", "attentive", "amplitude", "appellate", "anthology", "agitation", "assertive", "avalanche", "arbitrage", "anecdotal", "amazement", "agreeable", "arresting", "although", "analysis", "approach", "actually", "anything", "activity", "advanced", "addition", "achieved", "accepted", "acquired", "affected", "approval", "audience", "alliance", "aircraft", "anywhere", "academic",
"accurate", "assembly", "argument", "advisory", "adequate", "attitude", "attached", "apparent", "accident", "accuracy", "announce", "absolute", "adjusted", "assuming", "aluminum", "attorney", "abstract", "adjacent", "aviation", "artistic", "advocate", "appendix", "athletic", "autonomy", "abortion", "affinity", "advocacy", "appetite", "asserted", "antibody", "animated", "ambition", "abnormal", "airborne", "abundant", "acoustic", "assemble", "allocate", "adaptive", "activist", "affluent", "antelope", "analytic", "activate", "altitude", "automate", "aquarium", "applause", "arrogant", "asbestos", "annoying", "adhesive", "auspices", "archival", "adhesion", "analogue", "airfield", "attendee", "assorted", "allergic", "academia", "alkaline", "audition", "armchair", "additive", "amenable", "alphabet", "arterial", "airplane", "activism", "aromatic", "anterior", "avionics", "almighty", "abrasive", "ancestor", "aperture", "ancestry", "aerobics", "amortize", "auditory", "antidote", "another", "against", "already", "ability", "average", "account", "address", "achieve", "applied", "attempt", "article", "advance", "acquire", "absence", "attract", "assumed", "airport", "advised", "accused", "anybody", "ancient", "analyst", "adverse", "arrival", "academy", "alleged", "alcohol", "assured", "adviser", "auction", "airline", "assault", "anxiety", "arrange", "anxious", "approve", "archive", "amateur", "actress", "abandon", "appoint", "arsenal", "awkward", "analyze", "auditor", "anymore", "alright", "athlete", "antique", "analogy", "anytime", "awesome", "artwork",
"amusing", "ashamed", "amnesty", "apparel", "anatomy", "annuity", "apology", "admiral", "augment", "acclaim", "aquatic", "anomaly", "agility", "applaud", "antigen", "abusive", "allergy", "anguish", "analyse", "adjunct", "audible", "acrylic", "abolish", "ambient", "arrears", "abreast", "ammonia", "acreage", "airfare", "antenna", "adapter", "adamant", "angular", "abdomen", "arduous", "abiding", "amenity", "aspirin", "archaic", "aerobic", "asphalt", "artisan", "accrual", "austere", "algebra", "anarchy", "aerosol", "around", "across", "always", "access", "almost", "action", "actual", "annual", "amount", "august", "anyone", "active", "answer", "agency", "appear", "affect", "accept", "advice", "appeal", "attack", "author", "animal", "acting", "assume", "assist", "attend", "anyway", "aspect", "afford", "artist", "avenue", "assess", "abroad", "afraid", "agenda", "arrive", "advise", "allied", "arrest", "affair", "absent", "adjust", "assure", "autumn", "accent", "albeit", "aboard", "absorb", "asleep", "anchor", "advent", "atomic", "accord", "attach", "asthma", "attain", "aerial", "assert", "absurd", "assign", "admire", "arctic", "adhere", "artery", "alpine", "arroyo", "asylum", "arcade", "amidst", "ascent", "airing", "archer", "abrupt", "ageing", "armour", "aurora", "anthem", "abound", "accrue", "airbus", "apiece", "anemia", "astute", "affirm", "ashore", "accuse", "analog", "auburn", "acumen", "aspire", "ardent", "afloat", "apache", "almond", "antics", "aching", "advert", "apathy", "ascend", "arched", "about", "after", "among", "again", "above", "along",
"award", "allow", "alone", "ahead", "apply", "aware", "avoid", "agent", "asset", "agree", "adult", "apart", "audio", "aside", "audit", "array", "abuse", "alive", "argue", "apple", "acute", "arise", "adopt", "angry", "admit", "arena", "alike", "actor", "anger", "alert", "album", "alter", "angle", "alarm", "adapt", "angel", "alpha", "awful", "arose", "ankle", "ample", "alien", "arrow", "assay", "abbey", "alley", "awake", "aloud", "adobe", "amend", "armor", "await", "align", "altar", "aging", "atlas", "alloy", "amino", "amber", "aisle", "agony", "adept", "avail", "attic", "agile", "abide", "arson", "avert", "aroma", "annex", "aegis", "abbot", "apron", "awoke", "aspen", "arbor", "acorn", "aloft", "alias", "amiss", "aback", "angst", "adage", "axial", "ahold", "awash", "aloof", "aloha", "afoot", "abyss", "amuse", "adore", "axiom", "allay", "also", "area", "able", "away", "army", "acid", "aged", "anna", "anti", "acre", "auto", "amid", "aunt", "arch", "axis", "ally", "alto", "akin", "alas", "aide", "apex", "avid", "aura", "atom", "atop", "anal", "axes", "arid", "anew", "ache", "airy", "amen", "ante", "aero", "acne", "axle", "amir", "aria", "aqua", "arco", "awry", "afar", "acme", "alum", "arty", "axel", "agar", "amok", "anus", "ajar", "auld", "anil", "axon", "alms", "abbe", "ammo", "arse", "arum", "ahem", "aloe", "abut", "anon", "aeon", "aryl", "adit", "apse", "ahoy", "agio", "asci", "abed", "agon", "abet", "arvo", "aver", "achy", "agog", "axil", "agin", "alga", "anta", "alar", "agha", "acyl", "ague", "amyl", "agma", "ashy", "ayin", "alae", "ankh", "ayah",
"avow", "ambo", "amah", "alee", "aril", "alit", "aery", "alow", "alky", "and", "are", "all", "any", "act", "ago", "air", "age", "art", "ask", "add", "amp", "arm", "aid", "aim", "ace", "ate", "arc", "ash", "ana", "ave", "aye", "aha", "asp", "apt", "ark", "awe", "axe", "ale", "ant", "ala", "ass", "abs", "alt", "app", "aft", "ape", "ado", "aba", "ain", "arb", "aga", "ahi", "ait", "aah", "alp", "ail", "azo", "arf", "avo", "ani", "amu", "alb", "awl", "ane", "auk", "awn", "adz", "ais", "ami", "aal", "ads", "aas", "abo", "aby", "ama", "ahs", "aff", "als", "ags", "ars", "apo", "awa", "ays", "att", "ava", "as", "at", "an", "am", "ad", "ah", "ag", "ai", "aa", "ab", "ar", "aw", "ae", "ax", "ay", "al", "a"};

class BinaryTree {
private:
	float Average;
	string *Address;

	BinaryTree *Right;
	BinaryTree *Left;

	BinaryTree *Root = NULL;

public:
	void Insert(float _Average, string *_Address);
	void Inorder();
	void Show_Tree(BinaryTree *Current);
};

class Dictionary {
private:
	int Matched;
	int Total;
	float Average;
	
public:
	BinaryTree Search() {
		string Input, Word;
		BinaryTree BST;
		
		cout << "Enter a Word to Search  : ";
		cin >> Input;

		Start_Time = clock();

		Total = Input.length();

		for (int n_Word = 0; n_Word <= 1269; n_Word++) {
			Word = a[n_Word];
			Matched = 0;

			for (int i = 0; i < Total; i++) {
				if (Word[i] == '\0') {
					break;
				}
				else if (Input[i] == Word[i]) {
					Matched++;
				}
			}
			Average = Percentage();

			if (Average>49) {
				BST.Insert(Average, &a[n_Word]);
			}
		}
		return(BST);
	}

private:
	float inline Percentage() {
		return(((float)Matched / Total) * 100.0);
	}
};

void main() {
	Dictionary Ob;

	BinaryTree BST = Ob.Search();

	BST.Inorder();

	cout << "Results in " << (clock() - Start_Time) / double(CLOCKS_PER_SEC) * 1000 << " micro seconds." <<endl;
}

void BinaryTree::Insert(float _Average, string *_Address) {
	BinaryTree *NewBST_Node = new BinaryTree;

	NewBST_Node->Average = _Average;
	NewBST_Node->Address = _Address;
	NewBST_Node->Left = NewBST_Node->Right = NULL;

	BinaryTree **Temp = &Root;

	while (true) {
		if (*Temp == NULL) {
			*Temp = NewBST_Node;

			break;
	}
	else if (_Average <= (**Temp).Average) {
		Temp = &(**Temp).Left;
	}
		else {
			Temp = &(**Temp).Right;
		}
	}
}

void BinaryTree::Inorder() {
	Show_Tree(Root);
}

void BinaryTree::Show_Tree(BinaryTree *Current) {
	if (Current == NULL) { return; }

	Show_Tree(Current->Left);
	
	cout << *(Current->Address) << " : " << Current->Average << endl;

	Show_Tree(Current->Right);
}
