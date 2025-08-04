// Main Spring Boot Application
package com.herbalconnect;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class HerbalConnectApplication {
    public static void main(String[] args) {
        SpringApplication.run(HerbalConnectApplication.class, args);
    }
}

// Entity: Plant.java
package com.herbalconnect.model;

import jakarta.persistence.*;

@Entity
public class Plant {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String name;
    private String season;
    private String diseasesCured;
    private String description;
    private String imageUrl;

    // Getters and setters
}

// Entity: User.java
package com.herbalconnect.model;

import jakarta.persistence.*;

@Entity
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String email;
    private String password;

    // Getters and setters
}

// Entity: Shop.java
package com.herbalconnect.model;

import jakarta.persistence.*;

@Entity
public class Shop {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String name;
    private String contact;
    private String location;
    private String products;

    // Getters and setters
}

// Plant Repository
package com.herbalconnect.repository;

import com.herbalconnect.model.Plant;
import org.springframework.data.jpa.repository.JpaRepository;

public interface PlantRepository extends JpaRepository<Plant, Long> {}

// User Repository
package com.herbalconnect.repository;

import com.herbalconnect.model.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User, Long> {
    User findByEmail(String email);
}

// Shop Repository
package com.herbalconnect.repository;

import com.herbalconnect.model.Shop;
import org.springframework.data.jpa.repository.JpaRepository;

public interface ShopRepository extends JpaRepository<Shop, Long> {}

// Controller: AuthController.java
package com.herbalconnect.controller;

import com.herbalconnect.model.User;
import com.herbalconnect.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/auth")
public class AuthController {

    @Autowired
    private UserRepository userRepository;

    @PostMapping("/login")
    public String login(@RequestBody User user) {
        User found = userRepository.findByEmail(user.getEmail());
        if (found != null && found.getPassword().equals(user.getPassword())) {
            return "Login successful!";
        } else {
            return "Invalid credentials";
        }
    }

    @PostMapping("/register")
    public String register(@RequestBody User user) {
        userRepository.save(user);
        return "Registration successful!";
    }
}

// Controller: PlantController.java
package com.herbalconnect.controller;

import com.herbalconnect.model.Plant;
import com.herbalconnect.repository.PlantRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/plants")
public class PlantController {

    @Autowired
    private PlantRepository plantRepository;

    @GetMapping
    public List<Plant> getAllPlants() {
        return plantRepository.findAll();
    }

    @PostMapping("/add")
    public Plant addPlant(@RequestBody Plant plant) {
        return plantRepository.save(plant);
    }
}

// Controller: ShopController.java
package com.herbalconnect.controller;

import com.herbalconnect.model.Shop;
import com.herbalconnect.repository.ShopRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/shops")
public class ShopController {

    @Autowired
    private ShopRepository shopRepository;

    @GetMapping
    public List<Shop> getAllShops() {
        return shopRepository.findAll();
    }
}

// Image Recognition (Google Vision API integration pseudocode)
// Use external service and API Key for real use-case.

// Add Google Cloud Vision API dependency in pom.xml:
// <dependency>
//     <groupId>com.google.cloud</groupId>
//     <artifactId>google-cloud-vision</artifactId>
//     <version>3.16.0</version>
// </dependency>

// Example usage (VisionService.java):
// public String identifyPlant(MultipartFile file) throws IOException {
//     ImageAnnotatorClient vision = ImageAnnotatorClient.create();
//     ByteString imgBytes = ByteString.readFrom(file.getInputStream());
//     Image img = Image.newBuilder().setContent(imgBytes).build();
//     Feature feat = Feature.newBuilder().setType(Type.LABEL_DETECTION).build();
//     AnnotateImageRequest request = AnnotateImageRequest.newBuilder()
//         .addFeatures(feat)
//         .setImage(img)
//         .build();
//     List<AnnotateImageRequest> requests = Arrays.asList(request);
//     BatchAnnotateImagesResponse response = vision.batchAnnotateImages(requests);
//     return response.getResponses(0).getLabelAnnotations(0).getDescription();
// }