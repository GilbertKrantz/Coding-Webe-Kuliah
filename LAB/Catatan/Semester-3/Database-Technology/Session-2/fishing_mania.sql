-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 12, 2022 at 04:14 AM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.4.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fishing_mania`
--

-- --------------------------------------------------------

--
-- Table structure for table `customers`
--

CREATE TABLE `customers` (
  `customer_id` int(11) NOT NULL,
  `customer_name` varchar(50) NOT NULL,
  `customer_gender` varchar(10) NOT NULL,
  `customer_address` varchar(50) NOT NULL,
  `customer_email` varchar(50) NOT NULL,
  `customer_dob` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `customers`
--

INSERT INTO `customers` (`customer_id`, `customer_name`, `customer_gender`, `customer_address`, `customer_email`, `customer_dob`) VALUES
(1, 'Dirk Titterell', 'Male', '74 Melvin Point', 'dtitterell0@yellowpages.com', '2020-10-29'),
(2, 'Dukey Diano', 'Male', '92 Sugar Alley', 'ddiano1@state.com', '2020-09-27'),
(3, 'Alex Meekins', 'Male', '577 Dovetail Park', 'ameekins2@blogs.com', '2020-11-06'),
(4, 'Cherice Jermey', 'Female', '811 Debs Street', 'cjermey3@guardian.com', '2021-05-18'),
(5, 'Ingamar Carlin', 'Male', '389 Surrey Pass', 'icarlin4@shareasale.com', '2020-08-08'),
(6, 'Pooh McCutcheon', 'Male', '7 Melby Trail', 'pmccutcheon5@salon.com', '2020-08-03'),
(7, 'Silvain Jozsa', 'Female', '19269 Maryland Hill', 'sjozsa6@omniture.com', '2020-12-30'),
(8, 'Javier Drewson', 'Female', '8 Moulton Point', 'jdrewson7@home.com', '2020-08-20'),
(9, 'Wilbur Francino', 'Female', '21840 Golden Leaf Avenue', 'wfrancino8@wunderground.com', '2020-10-06'),
(10, 'Sadie Snow', 'Female', '70 Eagle Crest Hill', 'ssnow9@github.com', '2021-04-25'),
(11, 'Sofie Carmen', 'Female', '20196 Springview Plaza', 'scarmena@gov.com', '2020-11-20'),
(12, 'Amy Grenkov', 'Male', '2263 Weeping Birch Center', 'agrenkovb@aol.com', '2020-06-06'),
(13, 'Gabriela Scarf', 'Female', '920 Bobwhite Trail', 'gscarfc@skype.com', '2021-03-12'),
(14, 'Westley Boram', 'Female', '47 Darwin Terrace', 'wboramd@sun.com', '2020-09-03'),
(15, 'Hadleigh Playfoot', 'Female', '49 6th Junction', 'hplayfoote@msu.com', '2021-04-14');

-- --------------------------------------------------------

--
-- Table structure for table `fishermen`
--

CREATE TABLE `fishermen` (
  `fisherman_id` int(11) NOT NULL,
  `fisherman_name` varchar(50) NOT NULL,
  `fisherman_gender` varchar(10) NOT NULL,
  `fisherman_address` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fishermen`
--

INSERT INTO `fishermen` (`fisherman_id`, `fisherman_name`, `fisherman_gender`, `fisherman_address`) VALUES
(1, 'Clem', 'Male', '0975 Forest Dale Trail'),
(2, 'Dene', 'Male', '2 Grayhawk Parkway'),
(3, 'Lethia', 'Female', '905 Goodland Lane'),
(4, 'Tyrone', 'Male', '51745 Bowman Hill'),
(5, 'Shanda', 'Male', '848 New Castle Center'),
(6, 'Nani', 'Male', '3455 Village Green Court'),
(7, 'Dorothea', 'Male', '772 Goodland Park'),
(8, 'Chet', 'Female', '1 Merchant Street'),
(9, 'Darsie', 'Female', '31718 Toban Point'),
(10, 'Don', 'Male', '936 Lyons Plaza'),
(11, 'Tabby', 'Male', '10787 School Drive'),
(12, 'Desmond', 'Male', '8 Lien Junction'),
(13, 'Robenia', 'Female', '4 Dapin Avenue'),
(14, 'Curr', 'Female', '2 Veith Terrace'),
(15, 'Rudd', 'Male', '2 Hermina Park');

-- --------------------------------------------------------

--
-- Table structure for table `fishes`
--

CREATE TABLE `fishes` (
  `fish_id` int(11) NOT NULL,
  `fish_type_id` int(11) DEFAULT NULL,
  `fish_name` varchar(50) NOT NULL,
  `fish_price` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fishes`
--

INSERT INTO `fishes` (`fish_id`, `fish_type_id`, `fish_name`, `fish_price`) VALUES
(1, 5, 'Channel Catfish', 12.5),
(2, 4, 'Blue Marlin', 20.3),
(3, 3, 'Albacore', 10.3),
(4, 4, 'Sailfish', 30.5),
(5, 2, 'Red Grouper', 10.7),
(6, 3, 'Atlantic Bonito', 20.3),
(7, 4, 'Swordfish', 31.4),
(8, 3, 'Bigeye Tuna', 10.2),
(9, 4, 'White Marlin', 20.3),
(10, 1, 'Spotted Bass', 35.3),
(11, 3, 'Blackfin Tuna', 12.3),
(12, 3, 'King Mackerel', 15.3),
(13, 1, 'Striped Bass', 16.3),
(14, 5, 'Flathead Catfish', 8.1),
(15, 2, 'Gag Grouper', 39.4),
(16, 5, 'Blue Catfish', 7.4);

-- --------------------------------------------------------

--
-- Table structure for table `fish_types`
--

CREATE TABLE `fish_types` (
  `fish_type_id` int(11) NOT NULL,
  `fish_type_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `fish_types`
--

INSERT INTO `fish_types` (`fish_type_id`, `fish_type_name`) VALUES
(1, 'Bass'),
(2, 'Grouper'),
(3, 'Tuna'),
(4, 'Marlin'),
(5, 'Catfish');

-- --------------------------------------------------------

--
-- Table structure for table `transaction_details`
--

CREATE TABLE `transaction_details` (
  `transaction_id` int(11) NOT NULL,
  `fish_id` char(5) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction_details`
--

INSERT INTO `transaction_details` (`transaction_id`, `fish_id`, `quantity`) VALUES
(1, '11', 9),
(1, '15', 2),
(2, '16', 23),
(2, '6', 4),
(3, '15', 27),
(3, '7', 2),
(4, '1', 6),
(4, '14', 27),
(5, '14', 21),
(5, '3', 28),
(6, '15', 4),
(6, '2', 9),
(7, '15', 26),
(7, '4', 16),
(8, '5', 20),
(8, '7', 17),
(9, '2', 17),
(9, '5', 20),
(10, '10', 9),
(10, '4', 15),
(11, '12', 14),
(11, '14', 8),
(12, '16', 5),
(12, '9', 24),
(13, '4', 3),
(13, '5', 26),
(14, '10', 2),
(14, '14', 27),
(15, '2', 21),
(15, '5', 26);

-- --------------------------------------------------------

--
-- Table structure for table `transaction_headers`
--

CREATE TABLE `transaction_headers` (
  `transaction_id` int(11) NOT NULL,
  `customer_id` char(5) DEFAULT NULL,
  `fisherman_id` char(5) DEFAULT NULL,
  `transaction_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction_headers`
--

INSERT INTO `transaction_headers` (`transaction_id`, `customer_id`, `fisherman_id`, `transaction_date`) VALUES
(1, '2', '4', '2020-09-06'),
(2, '13', '15', '2020-06-05'),
(3, '7', '15', '2020-12-18'),
(4, '11', '15', '2020-12-15'),
(5, '10', '12', '2020-08-04'),
(6, '5', '5', '2021-02-19'),
(7, '6', '11', '2021-01-01'),
(8, '9', '13', '2021-04-28'),
(9, '1', '1', '2020-06-22'),
(10, '12', '9', '2020-06-13'),
(11, '5', '7', '2020-06-04'),
(12, '3', '1', '2020-07-28'),
(13, '15', '8', '2021-03-18'),
(14, '6', '1', '2020-08-22'),
(15, '3', '13', '2020-05-31');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customers`
--
ALTER TABLE `customers`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `fishermen`
--
ALTER TABLE `fishermen`
  ADD PRIMARY KEY (`fisherman_id`);

--
-- Indexes for table `fishes`
--
ALTER TABLE `fishes`
  ADD PRIMARY KEY (`fish_id`);

--
-- Indexes for table `fish_types`
--
ALTER TABLE `fish_types`
  ADD PRIMARY KEY (`fish_type_id`);

--
-- Indexes for table `transaction_details`
--
ALTER TABLE `transaction_details`
  ADD PRIMARY KEY (`transaction_id`,`fish_id`);

--
-- Indexes for table `transaction_headers`
--
ALTER TABLE `transaction_headers`
  ADD PRIMARY KEY (`transaction_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `customers`
--
ALTER TABLE `customers`
  MODIFY `customer_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `fishermen`
--
ALTER TABLE `fishermen`
  MODIFY `fisherman_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `fishes`
--
ALTER TABLE `fishes`
  MODIFY `fish_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `fish_types`
--
ALTER TABLE `fish_types`
  MODIFY `fish_type_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `transaction_headers`
--
ALTER TABLE `transaction_headers`
  MODIFY `transaction_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
