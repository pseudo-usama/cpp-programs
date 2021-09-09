-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 03, 2019 at 09:39 AM
-- Server version: 10.3.16-MariaDB
-- PHP Version: 7.3.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `map`
--

-- --------------------------------------------------------

--
-- Table structure for table `place`
--

CREATE TABLE `place` (
  `id` varchar(50) NOT NULL,
  `name` text NOT NULL,
  `lat` double NOT NULL,
  `lng` double NOT NULL,
  `icon` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `place`
--

INSERT INTO `place` (`id`, `name`, `lat`, `lng`, `icon`) VALUES
('01fbc2ffaec6cf762d2f5982281b569ae7c4230c', 'Sanmina Clinic', 32.19984829999999, 74.20024280000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('02c22c824319b3d1dfe780014db7effdb987060a', 'Hotel Corporate Inn', 31.4985477, 74.32648210000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('03b2520d87e91ad11d6c46f1b2decfe249e790f5', 'Dhallewali', 32.6567328, 74.4891705, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('0624417981ad9b2169e6d821a6c5404723ab1dfb', 'Mochi Gate', 31.5772078, 74.32154420000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('07217ada3940a2705ed47a95b1bd4b69e4db2a4f', 'Sadar Police Station Gujrat', 32.5692876, 74.0998171, 'https://maps.gstatic.com/mapfiles/place_api/icons/police-71.png'),
('08f96dd704bdf11cba29716ca668dbfab4a01956', 'Fatima Clinic', 31.7493905, 73.82495459999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('098ae959e0e6aa2143683955c89722f1d3090c76', 'Askri Bank ATM', 32.553402, 74.08868869999992, 'https://maps.gstatic.com/mapfiles/place_api/icons/bank_dollar-71.png'),
('09b72d4be727a41ccda29acbeecd392d7de552c3', 'Wali Clinic', 32.1715713, 74.21530189999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('0a3825b861a9c46cd56256fe9d6745b05c1ee897', 'Dubai Centre', 32.5763818, 74.0810037, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('0a559d6d32c814c080a56a63501220339d3dd104', 'Hamid Clinic', 32.2578841, 74.03610079999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('0af97949855d950e14410e9f3dc5c4aef0b746df', 'Park Lane Hotel', 31.5035636, 74.3493449, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('0d167811dd3b37797b3bd54b29062b91972317fc', 'Police Station Sharaqpur', 31.4654877, 74.10151389999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/police-71.png'),
('0f9ce52e8d0b52257e8e9598ba6a3a6abebaa910', 'Tuck Shop', 33.7616457, 73.2187318, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('1189d506b45b541e96ac8ac73a5b5a3c212edfcf', 'Al Muzammil Medical Centre', 32.5962696, 74.07717879999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('11f11a9d6889dc4250d35b2c1f792edbda4d1684', 'South East Wall', 31.5864378, 74.31484610000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('12a4916c881fa757252c9a443ded399431b096a3', 'Vision 3 CNG', 33.7418016, 73.18390640000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('12ef8c6bcda6cb27ce4ef7835dd7d20efdeb0ba4', 'Shamim Clinic', 33.7397846, 72.79847319999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('1441a91a2190085bf7868d857bad2d0b98d855b7', 'Zalha Bacha Centre', 33.9606831, 72.88353949999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('151e2a9b630ec1489a055492fb77ec2b7c21853a', 'Gujrat', 32.57307249999999, 74.10050439999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('1606d6877d69e8dec5d9d578d8295a19615cf812', 'Park', 31.47038900000001, 74.25200050000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('17541b39bdd6a291f6ed5531527ccf8ebf66d203', 'Zaib Clinic', 32.3558161, 73.98819920000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('17779b5dc64749a8ba908ea0366b0d8e450bf60d', 'Shahi Farm', 31.4533504, 74.76232770000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('1a6159dffd98de7725488a39b8df252b8955986d', 'Al Mustafa Welfare Trust', 31.4708481, 74.24511189999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('1aadf8b10cb41d276ea1f909c3751f60b20ca35d', 'Islamabad Hotel', 33.7160483, 73.08447219999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('1ab90bbfd23cc9fc1327cb4f1639d3194de7cc45', 'Khawaja Clinic', 33.6279301, 73.06190229999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('1b8db43c45d9cfeafb922cd3279f775e221b530d', 'Surraya Clinic', 32.55980609999999, 74.05707029999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('1c5cf7e5da3067d890c7d7c7d5ff50b62afb2195', 'Yasmeen Clinic', 32.4238882, 74.1151509, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('1df145a300d94e0c95cf5b20e622a9aacc3aa6ec', 'Hamza Clinic', 33.7648868, 72.76571809999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('1e7243168508f5e3c21f517ec90c11673581d8fc', 'Tabasum Clinic', 31.5323023, 74.26886560000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('1f4f2a1b5bb0e3c24594df53c1479465d9c8f33d', 'Zeshan Clinic', 33.9865617, 72.91096629999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('201e4cc2e1f5c25638dcd861fd28b875f20df565', 'Rana Clinic And Zacha Bacha Health Center', 31.6973043, 73.99967370000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('21082cb629db0113e65a708724612d3f77b062f2', 'Hussain Clinic', 32.56909, 74.05691209999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('211edbd8ca557184da564288d8744646e2228404', 'Meezan Bank Ltd.', 31.463014, 74.24441890000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('2257eefc86bfdef891c247aa3dc41a59cae4cffd', 'Kalsoom Clinic', 33.6366395, 73.04494279999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('22d415d47e80b6141dcf90696da8bfb40b32a1b6', 'Malot', 33.70875220000001, 73.21443980000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('25f060bee660e86a3c2beacb286b64988ac5e6c3', 'Al Rafah Clinic Maternity Home', 33.5813186, 73.02272070000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('2ba8e043ee02533926f0aebf28d7ceaadde0741e', 'Ali Trading Company', 32.56738599999999, 74.06778050000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('2c60be79af173b1b9165836c70adbeb92b4d8574', 'Pakistan Monument', 33.6933763, 73.06822069999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/museum-71.png'),
('2cdbb4e4e9c680b0c0e3032a1b960c341e7e93f7', 'Iqbal Clinic', 32.5941229, 74.07918510000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('2db251c002aa3c76f160e39c0453fdd3b8a13bbd', 'Shivalik Public Senior Secondary School Chabal Tarn Taran', 31.4661225, 74.7694798, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('2e92a4675fe236d3eca2332ba4d2c315dab07f73', 'Le Royal Guest House', 33.70832660000001, 73.04712270000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('2e9d4eab3ed262a179594b2975ee988c16dd9ffd', 'Hospitality Inn Lahore', 31.5615625, 74.32975799999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('3013a288bbcfdde976503fb5b97683c04bc82470', 'Fatima Gyne Center', 31.5513784, 74.2686966, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('31d8427a515b92e8b6cf6c918e155556ba86490d', 'Mushraf Clinic', 31.7521936, 73.8117072, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('345224be286de8ea3f3116e575ec0f40277037d6', 'Medi Citi Hospital', 32.2172143, 74.1727909, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('35345a42fa2a8cea6115f048e9698a87015c1843', 'Islamabad Store', 33.7300748, 73.07752670000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/shopping-71.png'),
('355785aa850624325c048d9c7afb15fea8ca4658', 'Tatly Aali Center', 31.9906362, 74.13421870000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('37d6d91056b7cfe7554435ba7111d52f8e2f16f8', 'Bismllah Clinic', 32.22116999999999, 74.15500309999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('37d7fb15ad6d98657166f8938782693422edc502', 'Najaf Clinic', 31.96268510000001, 73.9748204, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('3a04902e3a44b7cf7a37b00f034d9e523ef84f07', 'Perveen Clinic', 32.2234891, 74.22210930000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('3b407fe400da5f44cc06c6a5371a15ce6d11ca41', 'OYO Rooms Chheharta Road', 31.6295435, 74.81160920000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('3b9edd0598070bddb7cd79ef207db375fa076be0', 'Maududi Institute Masjid', 31.4970795, 74.26978830000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/worship_islam-71.png'),
('3caf88eeee508a7cfd5940598084ce67177a9666', 'Cheema Clinic', 31.9648605, 74.01428099999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('3d6a82ecc248be14487b70190856bc0cd45f5c0f', 'Bani Gala Super Store', 33.7112235, 73.16182939999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/shopping-71.png'),
('3d8d69e128a57ab494d6826b07b1022c89a0fe66', 'Al Mehmood Clinic', 31.96568420000001, 73.97597910000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('3e7e85a97a49349a6c918bba7506d88c754a74e0', 'The University of Lahore', 31.4605659, 74.24375510000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('3fa0f9e5050e90cd8a160b8dbbf731f0759ea5fa', 'Healers Center Hospital', 33.6328027, 73.06241399999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('408376e2fa2edda5e1c47f4f1690e5f7948587ff', 'Family Clinic', 33.664012, 73.09293630000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('422b76f63d923659164d7466ae663919b13208e9', 'Fatima Hospital', 32.5642119, 74.05712130000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('4260d82bbb9e167abf26c667f0f564428d8e3c1b', 'Vertex Total Solutions', 32.563308, 74.08045130000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('4312b52589555be9b7a1f6c460282cbed7864477', 'Syed Market Chak Sada gujrat', 32.5637098, 74.1341248, 'https://maps.gstatic.com/mapfiles/place_api/icons/shopping-71.png'),
('4535951f3b788b20ac93e85102fb40daef701113', 'Park', 31.4781592, 74.25487520000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('45731512600e83ad849ab4c9f0ef7156af282fe0', 'Eman Clinic', 32.38097169999999, 74.04405359999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('469153256033e2c556e8d8c7b319483d6c648a51', 'Noureen Ameen Clinic', 33.8365111, 73.29760280000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('497b0592b1a1fff50d54a47ee783d5158560eb02', 'THQ Hospital', 31.9639304, 73.97502859999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('49a407ac42bebdae07b90a59d13f7a4321c1237c', 'Rahet Health Clinic', 32.4434997, 74.11432739999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('4e954153a6f9d7779bf75dff03917a5b08eb56be', 'Nexus Grace Guest House', 33.713791, 73.082942, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('4efd3fc9fb3aff9a1da8a49ca2a048759b99e2b2', 'Tetra Pak Pakistan', 31.5389432, 74.35899189999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('5251ad48a41a4757b40360eebc6717d1ed2e2ba2', 'Fajjar Clinic', 31.4308328, 74.1740522, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('53324e453472380312d368dd8a80c2bca9289dfa', 'Rajput Motors', 32.5590193, 74.08389239999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('537aff3d300c736d9c7aad2c71ccfc1e5ed155a1', 'STARIHOTEL Chheharta Amritsar', 31.629558, 74.81004099999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('567d49b75c90cb21096fea76fb0623e74cf9bd1c', 'Naseem Clinic', 32.1680158, 74.20609119999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('56a8fee642420d96d10c50168fa4437ec24212fb', 'Daji Clinic', 33.7477179, 72.78208489999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('57588c12ca0d041f39b7b057af775b0f51b54abc', 'Lahore', 31.52036960000001, 74.3587473, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('5b6ca5c0eb9d9a07e652b1f2eecec94acec78e21', 'Dashmesh Public School', 31.5381112, 74.74324109999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('5ded561b20a178ff9047fb2a02f55fca2ea8f52e', 'Onfza', 31.5397183, 74.27134389999992, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('5f3f3aeafcfb22a247f32ddcb8f875b5d6d24544', 'Islamabad Serena Hotel', 33.715253, 73.10197629999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('5f903890c4eb6013db4cff784201079187d5160d', 'Mahnoor Clinic', 32.5642029, 74.09370119999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('60cc9727083a8cf03890c9577540455b439a2b2f', 'Syed Associates (Syed Ali Zain Architects ', 32.5856449, 74.10311449999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('611b8bf920efb2d754d412e44b5519a430d3c569', 'Shamim Clinic', 33.6498832, 73.08887470000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('623bb728a35ab8a2d7dbef34d5478f0e64c88ae3', 'Khawaja Medical Hall', 33.76487780000001, 72.7672791, 'https://maps.gstatic.com/mapfiles/place_api/icons/shopping-71.png'),
('630d1d726e87b855d2f73d33c38b856c737b8cdd', 'Munawer Clinic', 32.1736192, 74.17553539999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('64b6cef1a75347b50036a3e6533ce90d3aa86f5b', 'Punjab Medical Centre', 32.5942427, 74.08008369999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('664048ad2cbbe7c833e3baf369ecb28c64552f03', 'Government Primary School Cheema Khurd', 31.4821903, 74.67789070000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('66e12d0ddc42ca40cb893a46865cf280a00aaf91', 'Hassan Clinic', 32.5960256, 74.0768382, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('676bd86c79cb7525403cb1e692cfc174899c1e04', 'Faiza Nursing Home', 33.6298171, 73.02765060000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('68460a2d61d0843bf874c707089bdb56b0ad027b', 'Medicare', 33.6277211, 73.02699610000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('6953aac5d32a72ff2d2c5f21e869fa421a61edaa', 'Govt Primary School (Boys)', 32.5649413, 74.1123801, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('69a1d73d1d3488693a66cb853048ef61d7abecc3', 'Dhunni', 32.0602864, 73.79727849999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('6ac59d1b10c04a6fdb35cbb75efef4c57a42f222', 'Mangowal', 32.4938712, 73.89199589999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('6ac62df0e56c5768d9a4a58ce9c8841fd412bf19', 'Khuram Clinic', 31.7485055, 73.825019, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('6b2c4954206b8a7c1952a1175c5e6b261505c01a', 'Government Girls Secondary School Sharqpur District Sheikupura', 31.4663733, 74.10145280000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('6d57f3e0b3363c7dc4809c6ce17f2ebb6450cf24', 'Saira Clinic', 33.6704989, 73.00562089999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('6dbdf3b88aaf7fb20fc8df4c856e10327f73d34e', 'Zacha Bacha Center', 32.4372158, 74.11594749999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('6ef4b7159c09e55058ca38e85bc7b5353ec6b27e', 'Manoor Clinic', 31.6929066, 73.97145150000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('6fa9906a828fbf4a2d2b978643e34284dc05e940', 'Oriental Bank of Commerce', 31.4850549, 74.78155479999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/bank_dollar-71.png'),
('6fb999b8a39d6c1654b9bd1c331c365d040db6ce', 'Uzmas Clinic', 33.64023589999999, 73.0901662, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('713c5e4bb6f64b371889344ed954a773479da579', 'Al Shifa Ply Clinic', 33.5286341, 73.04970609999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('735761dabf1659172354c0dc37ff133de1467e77', 'Zaman Clinic', 33.9597147, 72.88332409999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('73cd970765e251c4819eb4bef680270c57f7ee1a', 'Jinnah Stadium Gujranwala', 32.1634164, 74.19115080000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('74397dd62dc3c1b520d1022057cf04371591ce42', 'VS College of IT And Arts', 31.485809, 74.790167, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('7445c6b5ccb439ad9b31f0690ad98df7fc9d9621', 'Sughrah Maternity Home', 31.79865259999999, 74.25549750000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('75b94f75ea0d8bf21947bb5ea038d999cecbe7e5', 'Zacha Bacha Centre', 33.5760882, 73.0286979, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('777a4611470945ad27c50f7882fba23ef01c58ab', 'Bank Alfalah ATM', 31.4551087, 74.21583899999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/atm-71.png'),
('7877164641cc3dade3204bb27cdba73cea94db5a', 'Riffat Clinic', 32.2526512, 74.16118030000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('78b3c509df64587036dd1144c22dd2be5e1f023a', 'Shifa Maternity Home', 31.70547849999999, 74.00147079999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('7ab14857c1d22484be80d8c2535c1f401100187e', 'Noor Clinic', 32.3225893, 73.90666540000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('7ba4ada07103e2114e784344f0e96d0ef060f1a6', 'Naila', 32.1213254, 74.1941071, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('7c08c03da0d3109c8b213ae2d37ed75928851615', 'Hamza Clinic', 31.53896799999999, 74.27978159999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('7c0fc9cebc1ce016e9ce1e27934a75fd80874c1d', 'Nagina Clinic', 31.7020556, 73.99105850000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('805562f5ccd7a9c66bc3327de4d5173d79cf094a', 'Sialkot', 32.4944991, 74.52289159999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('80a531332242357de933bf3598cec1291ddc5361', 'Ayesha Clinic', 33.5834157, 73.01631550000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('815508f11d3f46b10cf0c5c1b9092538da4597ea', 'Baqees Clinic', 31.747535, 73.8338354, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('82ca5f5a60267ee0a841b833e3d59b91fba135ce', 'Daska', 32.3362936, 74.36751679999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('8339d2136290ada57cb0f3d85e933d5c47ac7e6d', 'Khursheed Clinic', 32.4323396, 74.11571679999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('8ace9fc1750e069e10a00848552782a6ce12f522', 'Helar Medical', 33.7642937, 72.76610970000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('8bdb0a6bd125521fa793494169cafdb72302d99e', 'Rural Health Center', 31.4015666, 74.18174879999992, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('8c3abd38c70a8e72c778db26820f62642517b9b1', 'Dr Akhshanda Clinic', 32.24924859999999, 74.16348700000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('8c7b828544cb53beb6fbac91200c47afd6957386', 'Zacha Bacha Health Center', 32.4369713, 74.11805570000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('8d6b2699b68bfeef7809615302bead293b0e7ce5', 'Bakhshupura', 32.567873, 74.0762757, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('8f30b0fdf5fcc3dd60577e248ab4cbebbd78a7b9', 'Shri Baba Vaira Ji Dhand Kasel', 31.533749, 74.75850000000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/worship_general-71.png'),
('8f8fe157381acaa98b4f0e17719ef99d7c79d1aa', 'Ghulam Haider Family Clinic', 32.1616583, 74.17851810000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('8fae7c02a3bf08cc0e3b35a6354cccee2781a165', 'Z N Pharmacy', 32.5723132, 74.08219540000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/shopping-71.png'),
('91492cddeea51997968fcac0e47cb1e4eb002a9c', 'Masti Gate', 31.5875135, 74.31687310000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('9209594cbe61212ee3c65beafead0aa324cd387f', 'Bhu Khanawali', 32.1534405, 74.14297340000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('93dcaa9519af5d4975c064d4a1e85509352e413c', 'Al Qumar Medical Center', 33.83689010000001, 73.29826909999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('93f17a8ff1a7d13ada201e09967b7db576c92fd7', 'Rasheed Clinic', 31.93791, 73.99477999999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('953255603cfe95320f1473e1cf92c83a6943ef44', 'Abbasi Bakers ', 33.7369976, 73.17526900000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/restaurant-71.png'),
('9663af521ff0a8f0ce843d55879dca47e129e225', 'Minar-e-Pakistan', 31.5924933, 74.30950849999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/museum-71.png'),
('98e9a6d6cb7a5809450359760842db2d54cd6b8f', 'Cooperative Bank', 31.5090353, 74.69665780000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/bank_dollar-71.png'),
('9e71ac9e3e9d30319c609cdb8425b65c8a57f329', 'Mch Center', 32.4435993, 74.12520649999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('a22eca20133b944f1a88ded0504339ffca2d0465', 'Gujranwala', 32.1876919, 74.19445289999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('a419c72bec56f234f39d15b9ce54b39debc47a16', 'Qamar Clinic', 32.5466504, 74.01369090000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('a821974cd524b61972eea94a76bfc83561617d69', 'Rizwan Clinic', 32.2577729, 73.94317569999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('a856f09b53914cdcf1bfd4ef79405f023889402d', 'Sughran Healthy Care Center', 32.443726, 74.11706860000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('a9fad3d93be7a89782e0deb310161483db845060', 'Madni Auto Body Parts', 32.56337, 74.07758239999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('ab47ce4009f930711c8ef038350844ffadc618c7', 'Ahmed Clinic', 32.3786862, 74.00733679999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ab7d4f92cc9906586b463821233e83ba693dcb9e', 'Al-Madeena Sweet House Chak Sada Gujrat', 32.5636347, 74.13517690000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('ad784271428e5ccb2e25213f86438705f073bbb5', 'Aziz Bhatti Shaheed Hospital', 32.5990897, 74.07973770000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('adbffe21460a90b97c424849a5e3d6c208de988b', 'Arooj Clinic', 32.58442340000001, 74.09842189999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ae38719db311039c1c5b857b8a1846da7f3d0ea4', 'Pearl-Continental Hotel Bhurban', 33.9557394, 73.45962699999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('b12bdb4fc5d300a4988e223850572b9a5082365d', 'ViAROOMS Amritsar', 31.6295435, 74.81160920000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('b33f7310707d7f6e4b43226f55e9f667fe055ab9', 'Dhillion Combine', 31.4436733, 74.75668040000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('b3777b065bb60a4263db07295825a96233bf97b3', 'appointment for passport seva kender', 31.567141, 74.63565100000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/civic_building-71.png'),
('b41b872164b86dd2d245fedb83cce2ba87c34fa8', 'Gill Maternity Home', 31.7477916, 73.834742, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('b49760ca48d28baec1b999f730aab3b54e2f2587', 'Cantt Dispensary', 33.7634842, 72.76921130000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('b60d9fa125a0c6973936518659193ba03117b78d', 'Islamabad', 33.6844202, 73.04788480000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('b6680a32dcae912d4e9b96ca1c201be6648b722f', 'Ammar Clinic', 31.55523890000001, 74.26562549999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('b79300d961d609d987c5382acb2a2030287e8644', 'Fatima Medical Complex', 32.2011903, 74.20728469999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('b8d54ecdf365e9ed7e69b4946d323b2251a81929', 'Ceena Medical Centre', 33.56176389999999, 73.02240219999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('b9285fb3fbc2798e920bd5502944009d01d3683d', 'Four Star Fan Industry', 32.5432626, 74.09217620000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('b9594f6128c74ab3b84318705c09bf69d78faa62', 'Home Clinic', 32.5645171, 74.06018169999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('b95c73fce7788fcbaa87e4bd14622e7744ad1975', 'Al Shifa Hospital', 32.5935727, 74.07960730000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ba46a20904d8fd54e1f5b82003f8253625f3ee82', 'Railway Road Area', 32.5645713, 74.06673019999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('bb0fbd372f43cb23dd69865a920211cfe21f5831', 'Ali Baba Bakers', 33.7401404, 73.1798784, 'https://maps.gstatic.com/mapfiles/place_api/icons/restaurant-71.png'),
('bb7fefa3aab6c2bb215cc15d828cb4ddad0780fa', 'Malik Sweets ', 31.38414, 74.14866000000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/restaurant-71.png'),
('bc2a8e66c1df18a164e21e55ac38b6dced82ed85', 'Aashi Clinic', 33.7502314, 72.81429290000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('be62dcbc1b5a356bdc2789591937f0a1ed1413f1', 'Fazeelat Health Clinic', 32.2034963, 74.20857490000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('bf3ff0063fd4e7a643eb1d766700a4a04f4a7cdf', 'Wagah', 31.604757, 74.57413599999995, 'https://maps.gstatic.com/mapfiles/place_api/icons/civic_building-71.png'),
('bfdbb994d4c5084f23b90bd846775dc93cc0c244', 'Gezan Hospital', 32.2489562, 74.16327810000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('c2292b80c3a07efadade80ed07a6f36cb441dbc2', 'Park', 31.523352, 74.26499860000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_recreational-71.png'),
('c2be4bd593c8e2c9e8d3bdec07e41c37884a4b5b', 'Hasnain Clinic', 31.41051199999999, 74.22931369999992, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('c3cb8b6461838b8906530c9c179abf6a4bdc3de3', 'Chaudhry Cold Corner', 31.5194496, 74.14318230000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('c4a123e2002268f465ef0ce319ca349baf872cac', 'Sadda Pind', 31.644012, 74.81317949999993, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('c4bc47101fea63608ffae2389f02f06ae3ff5d14', 'Imran Medical Hospital', 31.6237531, 74.23480930000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('c54abe6eed5151fb9a96ef3001c62537d172cba3', 'Quran Mehal Shareef Gujrar', 32.5684806, 74.09962229999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/worship_islam-71.png'),
('c75ea907abdd648005bf56256d83e0a954bd0f7b', 'Mehak Clinic', 31.6999238, 73.99939319999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('c8046f5e0bf07bc47456d7563bb4ed228c2da95b', 'Layba Clinic', 32.16334370000001, 74.17713170000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('c9f4c404f2eaa8a88bfe3928255efe8f3d5c2f2b', 'Govt High School Chak Sada gujrat', 32.5655796, 74.13443389999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('ca41c73f640b28a61df070c9eead8f1a9418339b', 'Anjum Medical Center', 31.7469272, 73.83659009999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ca876afa5d925fa36498ce44d6c7afe5d1b9253d', 'Shireen Bakers ', 33.7394051, 73.18130359999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('cbdbbf82f9067b922ab653954e7ab5cbd2a4e49c', 'Ahmed Enterprises', 32.55911200000001, 74.0766873, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('cc0714330151d2638da63fb9753bcf7e4e9f5627', 'Punjab National Bank', 31.5093952, 74.69388779999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/bank_dollar-71.png'),
('cd828f7c6c3806c534bdb319e5c39b53b7031ba0', 'Ghazala Clinic', 32.4290207, 74.11627469999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('cf6df2e63b8e0d35791b363ea7defc42456de5c3', 'Staff Galla', 32.5634298, 74.05791850000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('d05b6a41509c0b6dac573a6aa18453ab5ca6801e', 'HMC Female Dispensary', 33.7724766, 72.81273720000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('d0d2a2e82cc4db54296a786a4eed8cf594cc542c', 'Amritsar', 31.6339793, 74.87226420000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('d1f93e368aa4ccf730eb3b4ee03d56d23f2806b7', 'Hotel One Down Town Lahore', 31.5743783, 74.30900339999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('d374c084ecdbf8c280ef2fa1ed77336a32708deb', 'Hadi Clinic', 33.8366069, 73.29799179999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('d3d6b386661145ed91e9282e2d05a3d949edcfb7', 'Lockwood Hotel Murree', 33.90663, 73.39074699999992, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('d417e0f026ff61c2a16d2321eabb12505c933bcf', 'Petrol Pump', 31.497076, 74.76836260000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/gas_station-71.png'),
('d4357d98dc45222052ae691cf502057a0d12fa94', 'Wazirabad', 32.44041790000001, 74.12025500000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('d4d31e58fb49dcbdadb16245fb8608afe32119fd', 'Dar-e-Arqam School', 31.4691386, 74.10596469999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('d534dbc281b7f253f0e7bf350c418cb5cdaec246', 'Rahwali Cantonments', 32.2545639, 74.11225059999992, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('d67925fba2d7479f2a5de950db503718c416907d', 'Muneeb Clinic', 32.3778594, 74.00651340000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('d6a4ee01408dd40f8dd03d14229007e617e3dd57', 'Victory Tailors', 32.5632193, 74.0656348, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('d75179e5fe47f5b619b231e38af5faf046cb5292', 'Naseem Clinic ', 32.5967849, 74.07102580000003, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('d930467029594c92391fc9b57ce4a5aabdc5254a', 'Ali Medical Center', 31.531701, 74.26908819999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('db6ac8b8727bbd04262a0f884bffc7626d5378cc', 'Sheikhupura', 31.7166617, 73.98502429999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('dcd42479c2fe092db68d6a56806dd89378a662a0', 'Al Shifa Clinic', 32.305765, 74.14707720000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('dcf756a46e11a5f34ba639d908aa2da63e24bcbc', 'Inayat Children Hospital', 32.5670037, 74.06611199999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('de60365ae681eaa3eea9fc0c7cade9d57dcd6ec8', 'Samia Clinic', 31.5118324, 74.2602412, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('e20033247ab4401f5784489b2f78f3887fde9234', 'Al-Safa Bakers ', 33.7405334, 73.18079109999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('e2ed9087029606127bbc7b991017f3ebb84af7a8', 'Manahil Clinic', 33.5720782, 73.02675469999997, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('e6c24a54406387540f0d020c550059b5654948e9', 'Tariq Clinic', 33.6230086, 73.05351240000005, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('e759fc4531c0534b3aab59df139b1ab8dbaf8583', 'Hina Clinic', 33.5760214, 73.02765729999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('e910d0333ef78ab62dd5cfe3d69d45cafbaf4527', 'Hotel Euro Heights Gujrat', 32.5763844, 74.06532240000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('e96c9c5601b133ee2560fc507c8a49d3a0339847', 'The Schazoo Pharmaceutical Laboratories Pvt Ltd.', 31.5499115, 74.17445610000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('e9cca45bacf7bef0dd2c9328ab4ba77fc1c04981', 'Samar Hospital', 32.5079499, 74.04317650000007, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ea1f6535221b2f254e8b2eb4953ecb019ac83f1f', 'Ayesha Clinic', 32.1743139, 74.16788580000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('eb50c40d8ec78438c2c6e61518dd02efb55673ee', 'Rawalpindi', 33.5651107, 73.01691349999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/geocode-71.png'),
('eb75b7f9a0d6249b486df4a63d95b8b10356d212', 'Envoy Continental Hotel', 33.71073659999999, 73.05948339999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/lodging-71.png'),
('ec08d000e2797414f5c0b71d77d9d81ba69450be', 'Shahnaz Clinic', 32.4309541, 74.11277169999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ed53281987a206ce2d95fff195e740b023e79be7', 'AWT Plaza', 33.6075284, 73.04697999999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('eda69d73817e86c4f0f99139ffbdb90485310ae9', 'Fatima Barkat Clinic', 32.5636604, 74.06320449999998, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('eeb97009959d59b8868a82944407bd926c0d283e', 'Khalil Hospital', 32.5627429, 74.05356299999994, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('ef3247ec8798166e986e3d1174f21e93f6259533', 'Schazoo Zaka Pvt Ltd', 31.54951, 74.17316400000004, 'https://maps.gstatic.com/mapfiles/place_api/icons/generic_business-71.png'),
('f187b2927ecd191c407e4347217effdb214e5309', 'Gurudwara Beerh Baba Budda Sahib Ji', 31.51280779999999, 74.77396850000002, 'https://maps.gstatic.com/mapfiles/place_api/icons/worship_general-71.png'),
('f1891f0d5244047feb672b00eda762bea81f00bb', 'Family Care Clinic', 33.6296786, 73.08181239999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f1bdb28765d5b352db2e704a50bb4a52b4fdcdc4', 'Majeep Clinic', 33.5703541, 73.046245, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f1ca2df9055043d954e17fa8f9b3922bde890002', 'Chenab Group Of Colleges Main Campus Gujrat', 32.59277219999999, 74.11573759999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('f1e136bb2695f01de504b1977b5a32e0ec3e1694', 'Arifa Clinic', 33.6598967, 73.00972960000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f325868e288d286ec367b8a7421c5305c0e008a0', 'University College Lahore', 31.4561413, 74.24452700000006, 'https://maps.gstatic.com/mapfiles/place_api/icons/school-71.png'),
('f45e2bc426d7173eee7885d9f51d023be8d498c8', 'Chuhan Medical Center', 32.5640718, 74.05792589999999, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f4c5da376b3fce6c8b7d23d37bbcc8e4704844c1', 'Azmat Hospital', 33.6408757, 73.07891029999996, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f572e8e319164fb3e54570f6ea188744ca82a005', 'Mahnoor Clinic', 33.9842169, 72.9216778, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f7e6fead3f87b91e76dfcc482fb2a545b016f8ad', 'Gulnaz Clinic', 32.15673089999999, 74.22575180000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png'),
('f7f17126f3e67d483262feda3f5c5df7add2312e', 'Bismillah Clinic', 32.2272466, 74.16842220000001, 'https://maps.gstatic.com/mapfiles/place_api/icons/doctor-71.png');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `place`
--
ALTER TABLE `place`
  ADD UNIQUE KEY `id` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
