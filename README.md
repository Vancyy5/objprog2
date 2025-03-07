# objprog

APRAŠYMAS:

Ši programa generuoja studentų duomenų failus su skirtingais įrašų dydžiai, vėliau juos išskirsto pagal jų galutinį balą į dvi grupes: kietekų(galutinis balas >=5.0 ) ir vargšų(galutinis balas < 5.0). Testavimai buvo atlikti su  penkiais atsitiktinias studentų sąrašų failais, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. 

1 TYRIMAS: FAILŲ GENERAVIMO LAIKAS

Buvo išmatuotas laikas, per kurį sugeneruojami nauji studentų sąrašų failai su atitinkamais dydžiais.

![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482135-bf792bf9-374e-4eba-ad6c-08635e16933b.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM1LWJmNzkyYmY5LTM3NGUtNGViYS1hZDZjLTA4NjM1ZTE2OTMzYi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0wZjdkNGI3ZTI2ZTRjYThkMzk4YmFmMmU1OTViODgyODA5Yjk5MTIwYmFmOWVmOGMxMWU4M2I3NzdjY2FmMmVhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.4hIIN3J3uEvgrP6EOABdu3YMndL5uo2c8cjGnykMGXc)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482142-720d4a5a-103a-4bfd-a8a6-c7e17c1ebcef.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTQyLTcyMGQ0YTVhLTEwM2EtNGJmZC1hOGE2LWM3ZTE3YzFlYmNlZi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0wOGZiY2JmMTAwMjhmNjFjZGFiZTY1YWI4N2VlYTczNGFmZDhlZmVjODk5YTdiNGE5OTNhYzEyYjU2OWU1OWViJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.DSnoZq-_Ty12Ks0_im3jmmoaFLdBu_Yj3m_cSDSL8cc)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482136-3d101f43-ea4c-4b21-bc5a-87750ebb0582.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM2LTNkMTAxZjQzLWVhNGMtNGIyMS1iYzVhLTg3NzUwZWJiMDU4Mi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mMmE1ZDFiNGRiZTJhYzE5OGU5MmU3OGRlYjQwNDJmY2U3ZWQ1Njk2ODU2OTNhOThjOWUzNzM2ODBmNWU0NjA4JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.Zb8e_z1pvcUsfRVPbOUPz7UaNpMdE949DJwaFjt-P0I)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482137-199851c9-d377-4b37-b3eb-d2ed6af69d03.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM3LTE5OTg1MWM5LWQzNzctNGIzNy1iM2ViLWQyZWQ2YWY2OWQwMy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jZmIxMTliMmJhNzFhNmU0YmY0Y2NlYTMzMzUyODU3MDY1ZWIzM2M3Y2JmNTgwMTc1OGJhZGFkMWUxNjhiYzgwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.BuRbiBP2_MmZAVUIvTgFIwlAnZLboSgqPGcqCLuDBCI)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482137-199851c9-d377-4b37-b3eb-d2ed6af69d03.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM3LTE5OTg1MWM5LWQzNzctNGIzNy1iM2ViLWQyZWQ2YWY2OWQwMy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jZmIxMTliMmJhNzFhNmU0YmY0Y2NlYTMzMzUyODU3MDY1ZWIzM2M3Y2JmNTgwMTc1OGJhZGFkMWUxNjhiYzgwJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.BuRbiBP2_MmZAVUIvTgFIwlAnZLboSgqPGcqCLuDBCI)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482133-6912eab5-fac4-4a27-a903-c4986821d5b0.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTMzLTY5MTJlYWI1LWZhYzQtNGEyNy1hOTAzLWM0OTg2ODIxZDViMC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xZDY2YjcxYzg0NzE1MjVmZjJmMDFiOTFiZDA4YWNiMDQ0MzhiYWQ2MDEyYmM3MzUwMTU3NDZkZTZjNWMzOGIxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.ACiL1KuhT0UWIGDcBp-3PtBgKEc8UVf342WEzy8BDbw)

2 TYRIMAS: DUOMENŲ APDOROJIMO LAIKAS

Buvo išmatuotas duomenų nuskaitymo iš egzistuojančio failo, studentų rikiavimo, rūšiavimo į dvi grupes bei rezultatų išvedimo į naujus failus sparta.

![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482139-75ef2327-5649-4437-8e05-4bc0bd46b6ba.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM5LTc1ZWYyMzI3LTU2NDktNDQzNy04ZTA1LTRiYzBiZDQ2YjZiYS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04N2UyMzk3NWIyYmRkZWYwNWIzYTZjOTM1NTE5OTk4Y2ZjMjhiZjRmMTViMDQ3YWI4YWJhYTgzMTY4OWJkZDY1JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.hrJMJWkRZf7Fqs3NN6x7FQsaZav_3HMU-hGrCkSVwq0)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482140-afaf3383-8f9f-4cf2-a00e-38307eecbc23.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTQwLWFmYWYzMzgzLThmOWYtNGNmMi1hMDBlLTM4MzA3ZWVjYmMyMy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zYzQ5NGU4NDA4NDIxNjY1NjI1OWZkNmM2OTZjZTA3NDYwYWZhM2U1OWY0M2FlMmZlMTJmZDRhODhmMjc3NDVkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.zH_POjRqOI_UJge1VY8OPkEaOeh6H1cnLC0Mps-9Ff0)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482138-1d20d928-cd7c-420f-bb43-1ca68e4f7f55.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM4LTFkMjBkOTI4LWNkN2MtNDIwZi1iYjQzLTFjYTY4ZTRmN2Y1NS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yODRkMzRiYzY3ZWJhOWVjNWNkOGFjOTc3OWQ5MTJkOWNjNmE4MGExMjFkMDE4ZTU1NGJmNDZhZWJlZGExMmFlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.TCl50SKc0sm_GJijghUudyVAvDz2uXk_ldNnvgOTBr8)
![Screenshot](https://private-user-images.githubusercontent.com/184347555/420482134-93c30b6c-56fe-4077-a4d3-a59125d19f01.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NDEzNzc5MzIsIm5iZiI6MTc0MTM3NzYzMiwicGF0aCI6Ii8xODQzNDc1NTUvNDIwNDgyMTM0LTkzYzMwYjZjLTU2ZmUtNDA3Ny1hNGQzLWE1OTEyNWQxOWYwMS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMzA3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDMwN1QyMDAwMzJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xNDdkODkyMmY3NGFjN2RlMDk1OTY4ODQ3MzQ2Zjg0MWE4OWJmMzM0ZjZjYTAzZDJjYzIzOWRjNGVmN2YyY2IyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.q086W93lcUTEHKaQWDMjDsQXZCa0jlx1leZYgnY4F4s)

Kiekvieno failo vidutiniai laikai: