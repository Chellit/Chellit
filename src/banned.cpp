#include <consensus/tx_verify.h>
#include <uint256.h>
#include <map>

typedef std::map<uint256, int> BannedInputs;

const BannedInputs bannedFunds = {
	{
		// CJTq6DbcKjr682yja4JR1XMy3AGk8fDUhM 
		{ uint256S("0x777f699d243750667d9074b6a1de477920b0f714e30fe841ad59fee761f1e0a3"), 0 },
		// CN4c3HkRZa8FS4mdgLz2FtABpYBiUYH6Xv
		{ uint256S("0xdb4d9e23211662fc07f55bcc5e8785c441cfe63f9e05aad1a0e3a44e0e66f2f5"), 1 },
		{ uint256S("0xcd8eab65da1baaa2c8aabbe8b9afd27ff2a50b6f4b951e31bfe29aa0d07a1ef3"), 1 },
		{ uint256S("0x777f699d243750667d9074b6a1de477920b0f714e30fe841ad59fee761f1e0a3"), 1 },
		// CJJzXaPkHCHFUwz24f7AyqexfLJxRMTVmu
		{ uint256S("0xfd8df1353c3e7dfe134dd5edef45dda5e82021b47086c9962da3a39b60d49d7f"), 1 },
		{ uint256S("0x25fc5d70d98f5e42df0c720783127338246daf2ccd5b3fd731e39483a52502a6"), 1 },
		{ uint256S("0x09c4872692289af454b1f227e170afe655a309dd8e37498823bde1822e1548fa"), 1 },
		{ uint256S("0x9438a7db5a6dd81352a1e34c5e5dc455fd65bd8b67a749ea4cb74b0ca1770226"), 1 },
		// CHM47q85K3J7MedQ2wLntdoVitEaHYWe6u
		{ uint256S("0xb035aa73d11778ad204d698b50a38fa54b6c6ec3218e2b9dd8f66b418251e43e"), 1 },
		// CXbJ37qiaxqsXfu1eYak3wEBL5nejQoaSa
		{ uint256S("0x7752bc554da256f2b704184a42bd40d650f9d441dffc732418ac6710b6df0c39"), 0 },
		// CLesiBPgp1m2jFGwbYGGr19j5L4dH4Kjgk
		{ uint256S("0x0ab887b908d2c63653b1c34cb45ca547ca771b7b739d3048268d120ea2502fff"), 1 },
		//CLPcqJ1XWtapWxsDWTQ5kuM5SZyB4EP4gn
		{ uint256S("0xb5dcace21af17da010fc883f8285a85bcd6e6277cac09490169cd33fcb761c4d"), 0 },
		// CdCim7Uiu1rvbwKAe5qGb7YHZA1McvKM4t
		{ uint256S("0x29ff67dcbd6d39be781405f16002924259f171f0cd7b9a3e0da230ded47c56f8"), 0 },
		// CPQA8n62SR4vy4NsN2zgQY1iXqKGGrLNQ2
		{ uint256S("0x38aeb99d594d7625e06424153cd1344126b2324b8d99f326218fc01c5cc8cf29"), 1 },
		// CPHC3Pfd3Ma4kmWRujWXEAydq1iyHxGpaJ
		{ uint256S("0x6093d05f7669269fe847c5821f4a7ce0273bd80f762b7b771acd463c05568c77"), 0 },
		// CR9FikZ28zjycSzRXbZFfvH5rxdWLxWaqj
		{ uint256S("0x4151ea99330f67e604c6af89b1f8793332e46a1f4470e4fd0d547c84417b1b86"), 0 },
		// CQwkAcQhwTLp7miEdENvVJMTqY5TsZHKQe
		{ uint256S("0x1f5463179263cd57e26903e24c97635a736ffe093d4dcd918a25c456e63ee817"), 0 },
		// CPosMg3dzpQgGtmUekDEoqqnWZ7cJpsrbm
		{ uint256S("0xb8bff08a755bcb2d4f7b6ab017b1b4420f3944340ce678c5a2d63165605f34d8"), 0 },
		// Cf1g9iXqFiMt7vSmmKyNYGzH7CT7Za4RYw
		{ uint256S("0x94fce10a33e5e485aa528021ab15210e6c1c4a81c2ed5b9254cd249d6a49e3e1"), 1 },
		{ uint256S("0x0ec04f2834b5f75320bc9a109ecf116e44c2f89b570f77890dce9eecd9542df8"), 1 },
		{ uint256S("0x51382a34997e2f1bbdf615545e4495c988d7d28915862ff06d7095fab54c8763"), 1 },
		{ uint256S("0x7752bc554da256f2b704184a42bd40d650f9d441dffc732418ac6710b6df0c39"), 1 },
		{ uint256S("0xe4442b1fbef56ebeaf31c739c6714939fb9f399ac9c31cc67f3bc714e45ded37"), 1 },
		{ uint256S("0xb8bff08a755bcb2d4f7b6ab017b1b4420f3944340ce678c5a2d63165605f34d8"), 1 },
		{ uint256S("0xcb7b91628193e5fe3a50e7bf3fd7c84a8b33b869903a48da37aa959892571fbf"), 0 },
		{ uint256S("0xb4a98d3a12787e4f3d47edf925a494b7d38339db9ae97c6c78a40ab7e4755465"), 0 },
		{ uint256S("0xf8b02d708f0fed5d7c95e5c8173181cf9ed5c42d918ad53aed49351d588cdf54"), 1 },
		// CLT2oKbTJEvJcCxvW643SYUz6Upm7aisBD
		{ uint256S("0x1727ba8867b260e3e65ad436d3bd423d0352cab583483a9b6af4531fa6cdf960"), 1 },
		// CUoH1ksZSkqH27CpUyW3NdkTjTzPqi7JHh
		{ uint256S("0x1cbd4385174224f9034e04586c8b5fb2d2e0eedfab1bb26dd561e5184a3de952"), 0 },
		// CKh96qCGMMRaWk7nxzbUPmNr5CvDALsBsh
		{ uint256S("0x7ebab31a60c91a195129e3c932cc162e58dab06004347083e8ca4e8556636642"), 0 },
		{ uint256S("0xb94ada90c129a599053094a9dad414f63fda5750930e19ba1a77df2ffc69ae6d"), 1 },
		{ uint256S("0xcf8cbbe94ca064870414f3129a114ff963a398662f1fb0494e40bc99e9805640"), 1 },
		{ uint256S("0x2c2df276d253e32948d64c39b2139f1232f08a24b34ad701625884cea4e68be7"), 1 },
		{ uint256S("0x71e1cd7c4af40fb6ecc6457c61071b6fd1651a42e3325587ec5405bdd69fdf76"), 1 },
		{ uint256S("0x789e21f9412aa815e8ee05fe9666c3ea10e9f066e3991854b9dc21bf20e96351"), 1 },
		{ uint256S("0xc3e6530cac383c1a45af9aba4db2914cccedb7ca4a91f2821203127169f510b3"), 1 },
		{ uint256S("0xbf686fb2a4f080f2db89bc9502693fa126c87c40e68e005395c916f2a0f1419b"), 1 },
		{ uint256S("0x5b1d2a761d14fc3a69b48fbf1ae9e7a1f7e0b267855d37f544aba23af900e02c"), 1 },
		{ uint256S("0x1cbd4385174224f9034e04586c8b5fb2d2e0eedfab1bb26dd561e5184a3de952"), 1 },
		// CeHqsRFkzdTw1RGxpgD49G7eHn3oodNv1p
		{ uint256S("0xf09eeb4ad4c6c2743f97bbdff184853c9c8cb4a334e84b77c0034742d3ccc552"), 1 },
		// Ce7RySAim6gW1nn41qH8jKdFvsKuv3TdJf
		{ uint256S("0xaad6d7077c650f0affd0e34ee7f21dc2d01d85f13ae9ae59896a161a6e1c22cc"), 1 },
		{ uint256S("0x56b6e3c8aff14a795aedfc54b901f4e9545ce4682618cacb54146845249fbc41"), 1 },
		// CXo6W2TMocRnGBSwn5tXpWCwEEKm6nBoaf
		{ uint256S("0x835610a91f9b22c36cd5ce66874b945c6ac28a3756b3f5b22612a06438722757"), 1 },
		{ uint256S("0x5eda4d606a24be2399994af41991a854f93c9d58500f2c20032384fb58765c25"), 1 },
		{ uint256S("0x0aeed24a179ca2755878e376a942c7b1763262deea2412536b3425a2cb2b6038"), 1 },
		{ uint256S("0xd21ac70cdd7892ccdcf2fac8517f64f850bdfc56bac0cdfaf57d79fe0b0d7457"), 1 },
		{ uint256S("0xce2983f1c3da3cebb4ccb56b9ebf77bec8627f83903fd8cc9531e1787395b1ab"), 1 },
		// CW3PHRf6vnmTPYNzXx75Mw9sJbDZKshpTU
		{ uint256S("0x0fcb1446398109dffbb48d774be74ad4f3a57c22099689ab297a70b2a5353fd4"), 1 },
		{ uint256S("0x750876449690363030e78f92633d06423ef66ecd64ffc45744bae9155e2681b4"), 0 },
		{ uint256S("0x8dbe751e8559a7aec4b6888a40d6bb3f11bab4c3b9c5c27c61bd8eb4c8a76130"), 1 },
		{ uint256S("0xb7948b53329c7c4f2e3d85be729fbe05ab2463f2c85c77797c71914e425bb1d2"), 0 },
		{ uint256S("0x4172404b0a4ae94e47bd9da07695615a0162b4ab94266bc5e524f60a8e16ef6d"), 0 },
		{ uint256S("0x58eb9c5ab50a6bf51c74c182c71f9fc60ef8c7582a6e822b49c598a42b1a979d"), 0 },
		{ uint256S("0x6beca070b991dadd5654ee162940a4ee12982740503dceec8c0a03080bab3641"), 0 },
		{ uint256S("0xeae844a0a67636ebf18a96bac7cb8d84b6634cf8c4ad3f68cbbba3651a134d56"), 1 },
    }
};

bool areBannedInputs(uint256 txid, int vout) {
	for (auto inputs : bannedFunds) {
		if (inputs.first == txid && inputs.second == vout) {
			return true;
		}
	}
	
	return false;
}
