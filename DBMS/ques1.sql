-- MySQL dump 10.16  Distrib 10.1.21-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: localhost
-- ------------------------------------------------------
-- Server version	10.1.21-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Department`
--

DROP TABLE IF EXISTS `Department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Department` (
  `Dno` int(11) NOT NULL,
  `Dname` varchar(50) DEFAULT NULL,
  `Location` varchar(50) DEFAULT 'New Delhi',
  PRIMARY KEY (`Dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Department`
--

LOCK TABLES `Department` WRITE;
/*!40000 ALTER TABLE `Department` DISABLE KEYS */;
INSERT INTO `Department` VALUES (10,'Accounting','New York'),(20,'Research','Dallas'),(30,'sales','Chicago'),(40,'Operation','Boston'),(50,'Marketing','New Delhi');
/*!40000 ALTER TABLE `Department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Employee`
--

DROP TABLE IF EXISTS `Employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Employee` (
  `Eno` char(3) NOT NULL,
  `Ename` varchar(50) NOT NULL,
  `Job_type` varchar(50) NOT NULL,
  `Manager` char(3) DEFAULT NULL,
  `hire_date` date NOT NULL,
  `dno` int(11) DEFAULT NULL,
  `commission` decimal(10,2) DEFAULT NULL,
  `Salary` decimal(7,2) NOT NULL,
  PRIMARY KEY (`Eno`),
  KEY `dno` (`dno`),
  KEY `Manager` (`Manager`),
  CONSTRAINT `Employee_ibfk_1` FOREIGN KEY (`dno`) REFERENCES `Department` (`Dno`),
  CONSTRAINT `Employee_ibfk_2` FOREIGN KEY (`Manager`) REFERENCES `Employee` (`Eno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employee`
--

LOCK TABLES `Employee` WRITE;
/*!40000 ALTER TABLE `Employee` DISABLE KEYS */;
INSERT INTO `Employee` VALUES ('736','Smith','Clerk','790','1980-02-20',20,0.00,1000.00),('749','Allan','Sales_man','769','1981-02-20',30,300.00,2000.00),('752','Ward','Sales_man','769','1981-02-22',30,500.00,1300.00),('756','Jones','Manager','783','1981-04-02',20,0.00,2300.00),('765','Martin','Sales_man','787','1981-04-22',30,1400.00,1250.00),('769','Blake','Manager','783','1981-05-01',30,0.00,2870.00),('778','Clark','Manager','783','1981-06-09',10,0.00,2900.00),('783','King','President',NULL,'1981-11-17',10,0.00,2950.00),('784','Turner','Sales_man','769','1981-09-08',30,0.00,1450.00),('787','Adams','Clerk','778','1983-01-12',20,0.00,1150.00),('788','Scott','Analyst','756','1982-12-09',20,0.00,2850.00),('790','James','Clerk','769','1981-12-03',30,0.00,950.00),('792','Ford','Analyst','756','1981-12-03',20,0.00,2600.00),('793','Miller','Clerk','788','1982-01-23',40,0.00,1300.00);
/*!40000 ALTER TABLE `Employee` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-02-18  9:41:29
